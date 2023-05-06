#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <cstring>
#include "Imu_CH0X0.h"

using namespace std;

Imu_CH0X0::Imu_CH0X0(const char *serial_name, uint32_t bps = 115200)
{
    strncpy(this->serial_name, serial_name, 32);
    this->bps = bps;
}

Imu_CH0X0::~Imu_CH0X0()
{
    serial.close_serial();
}

int Imu_CH0X0::init_serial()
{
    return serial.open_serial(this->serial_name, this->bps);
}

int Imu_CH0X0::parse_msg(uint8_t *msg, uint8_t len)
{
    struct serial_package *pack = (struct serial_package *)msg;
    if (pack->frame_head != FRAME_HEAD && pack->frame_type != FRAME_TYPE)
    {
        printf("not CH0X0 seerial package\n");
        return -1;
    }
    // 浪费算力,没必要计算crc
#ifdef ENABLE_CRC
    uint16_t crc = this->cal_crc(pack);
    if (crc != pack->crc)
    {
        printf("imu crc not right\n");
        return -2;
    }
#endif
    struct data_package *data = &(pack->data);
    if (data->tag != TAG_ID)
    {
        printf("not CH0X0 data package\n");
        return -1;
    }
#ifdef debug
    printf("温度%d 气压%f 时间%u \n", data->tempertaure, data->pa, data->time);
    printf("加速度 %f %f %f \n", data->accelerometer_x, data->accelerometer_y, data->accelerometer_z);
    printf("角速度 %f %f %f \n", data->gyroscope_x, data->gyroscope_y, data->gyroscope_z);
    printf("欧拉角 roll %f, pitch %f, yaw %f \n", data->roll, data->pitch, data->yaw);
    printf("四元组 %f %f %f %f \n", data->quaternion_w, data->quaternion_x, data->quaternion_y, data->quaternion_z);
#endif

    return 0;
}

int Imu_CH0X0::sync_read(uint8_t *buf, uint32_t buf_len)
{
    fd_set rd_set;
    struct timeval tv;
    int ret;
    int len = 0;
    int sum_len = 0;
    int fd = serial.get_serial_fd();

    while (1)
    {
        FD_ZERO(&rd_set);
        FD_SET(fd, &rd_set);
        tv.tv_sec = 2;
        tv.tv_usec = 0;
        ret = select(fd + 1, &rd_set, NULL, NULL, &tv);
        if (ret == -1)
        {
            perror("select error");
            return -1;
        }
        else if (ret == 0)
        {
            printf("select timeout\n");
            // continue;
        }
        else
        {
            if (FD_ISSET(fd, &rd_set))
            {
                // ch0x0模块 串口读两次数据: 64+18
                char recv[128];
                len = read(fd, recv, 128);
                if (len > 0 && len <= 64)
                {
                    memcpy(buf + sum_len, recv, len);
                    sum_len += len;
                }
                else if (len <= 0)
                {
                    printf("recv failed len=%d, error=%d::%s\n", len, errno, strerror(errno));
                    sum_len = -1;
                    break;
                }

                if (sum_len > 64)
                    break;
            }
        }
    }

    return sum_len;
}

const uint8_t TAG_ID = 0x91;
#pragma pack(1)
struct data_package
{
    uint8_t tag;
    uint8_t used1;
    uint8_t used2;
    int8_t tempertaure;
    float pa;
    uint32_t time;
    float accelerometer_x; // 加速度
    float accelerometer_y;
    float accelerometer_z;
    float gyroscope_x; // 角速度
    float gyroscope_y;
    float gyroscope_z;
    float magnetometer_x; // 磁场计
    float magnetometer_y;
    float magnetometer_z;
    float roll;         // 欧拉角 roll横滚角 -180~180
    float pitch;        //       pitch俯仰角 -90~90
    float yaw;          //       yaw  航向角 -180~180
    float quaternion_w; // 四元组
    float quaternion_x;
    float quaternion_y;
    float quaternion_z;
};

const uint8_t FRAME_HEAD = 0x5a;
const uint8_t FRAME_TYPE = 0xa5;
#pragma pack(1)
struct serial_package
{
    uint8_t frame_head;
    uint8_t frame_type;
    uint16_t len;
    uint16_t crc;
    struct data_package data;
};

// 成员变量
Serial serial;
char serial_name[32];
uint32_t bps;

uint16_t Imu_CH0X0::cal_crc(struct serial_package *pack)
{
    uint8_t *p = (uint8_t *)pack;
    uint16_t crc = 0;
    this->crc16_update(&crc, p, 4);
    this->crc16_update(&crc, p + 6, pack->len);

    return crc;
}

void Imu_CH0X0::crc16_update(uint16_t *currectCrc, const uint8_t *src, uint32_t lengthInBytes)
{
    uint32_t crc = *currectCrc;
    uint32_t j;
    for (j = 0; j < lengthInBytes; ++j)
    {
        uint32_t i;
        uint32_t byte = src[j];
        crc ^= byte << 8;
        for (i = 0; i < 8; ++i)
        {
            uint32_t temp = crc << 1;
            if (crc & 0x8000)
            {
                temp ^= 0x1021;
            }
            crc = temp;
        }
    }
    *currectCrc = crc;
}
