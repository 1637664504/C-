#include <iostream>
#include <stdint.h>
#include <stdio.h>
using namespace std;

class Imu_CH0X0
{
public:
    int parse_msg(uint8_t *msg, uint8_t len)
    {
        struct serial_package *pack = (struct serial_package *)msg;
        if (pack->frame_head != FRAME_HEAD && pack->frame_head != FRAME_TYPE)
        {
            printf("not CH0X0 seerial package\n");
            return -1;
        }
        // 浪费算力,没必要计算crc
#ifdef ENABLE_CRC
        uint16_t crc = this->cal_crc(pack);
        if(crc != pack->crc)
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

private:
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

    uint16_t cal_crc(struct serial_package *pack)
    {
        uint8_t *p = (uint8_t *)pack;
        uint16_t crc = 0;
        this->crc16_update(&crc,p,4);
        this->crc16_update(&crc,p+6,pack->len);

        return crc;
    }

    void crc16_update(uint16_t *currectCrc, const uint8_t *src, uint32_t lengthInBytes)
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
};

int main(int argc, char *argv[])
{
    uint8_t imu_data[] = {0x5a, 0xa5, 0x4c, 0x0, 0xb6, 0x35, 0x91, 0x1, 0x0, 0x23, 0x0, 0x0, 0x0, 0x0, 0x79, 0xf,
                          0x0, 0x0, 0x5d, 0x7d, 0x8e, 0xbd, 0xf8, 0x43, 0xb3, 0x3d, 0xd1, 0xc0, 0x7e, 0x3f, 0xb7, 0x6b,
                          0x15, 0xbf, 0x8e, 0x2b, 0x15, 0x3e, 0xdd, 0x66, 0xb4, 0x3c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                          0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8e, 0x81, 0x81, 0x40, 0xe1, 0xdc, 0x9f, 0x40, 0xf3, 0x9,
                          0x55, 0x3c, 0xe5, 0x98, 0x7f, 0x3f, 0x5a, 0x62, 0x32, 0x3d, 0x2f, 0x83, 0x10, 0x3d, 0xb0, 0x8d,
                          0xd8, 0x3a};

    Imu_CH0X0 imuImpl;
    imuImpl.parse_msg(imu_data, sizeof(imu_data));

    return 0;
}
