#include <stdint.h>
#include "Serial.h"

#ifndef __imu_ch0x0__h
#define __imu_ch0x0__h
class Imu_CH0X0
{
public:
    Imu_CH0X0(const char *serial_name,uint32_t bps);
    ~Imu_CH0X0();
    int init_serial();
    int parse_msg(uint8_t *msg, uint8_t len);
    int sync_read(uint8_t *buf,uint32_t buf_len);

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

    // 成员变量
    Serial serial;
    char serial_name[32];
    uint32_t bps;

    uint16_t cal_crc(struct serial_package *pack);
    void crc16_update(uint16_t *currectCrc, const uint8_t *src, uint32_t lengthInBytes);
};
#endif