#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

#include "lib_serial.h"

#define R6082V_HEAD0 0xAA
#define R6082V_HEAD1 0x00
#define R6082V_RESERVED 0x55
typedef unsigned short half_float16;

#pragma pack(1)         //关闭内存对其 --> 结构体与数据对齐
struct R6082V_frame
{
    uint8_t head0;
    uint8_t head1;
    uint8_t index;
    half_float16 yaw;
    half_float16 yaw_acc;
    half_float16 roll;
    half_float16 pitch;
    half_float16 acc_x;
    uint8_t reserved;
    uint8_t checksum;
};

struct imu_data
{
    float yaw;
    float roll;
    float pitch;
    float acc_x;
    float acc_y;
    float acc_z;
};

float Float16ToFloat(half_float16 fltInt16 )
{
    float ret;
#if 1
    int fltInt32    =  ((fltInt16 & 0x8000) << 16);
    fltInt32        |= ((fltInt16 & 0x7fff) << 13) + 0x38000000;
    memcpy( &ret, &fltInt32, sizeof( float ) );
#else
    ret = float(fltInt16);
#endif
    return ret;
 }


void parse_msg(uint8_t msg[],int len)
{
    if(len == 15
        && (msg[13] != R6082V_HEAD0)
        && (msg[0] == R6082V_HEAD0 && msg[1] == R6082V_HEAD1))
    {
        struct R6082V_frame *frame = (struct R6082V_frame *)msg;
        struct imu_data imu = {0};
        imu.yaw = Float16ToFloat(frame->yaw);
        imu.roll = Float16ToFloat(frame->roll);
        imu.pitch = Float16ToFloat(frame->pitch);
        imu.acc_x = Float16ToFloat(frame->acc_x);
        imu.acc_y = Float16ToFloat(frame->yaw_acc);
        imu.acc_z = 0;
        printf("yaw:%f roll:%f pitch:%f acc_x=%f acc_y=%f recv=%x sum=%d\n",
            imu.yaw,imu.roll,imu.pitch,imu.acc_x,imu.acc_y,
            frame->reserved,frame->checksum);
    }
    else
        printf("报文校验不通过\n");
}

int loop_read(int fd)
{
    fd_set rd_set;
    struct timeval tv;
    int ret;
    uint8_t buf[256];

    while(1){
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
            continue;
        }
        else
        {
            if (FD_ISSET(fd, &rd_set))
            {
                int len = read(fd, buf, sizeof(buf));
                if (len > 0)
                {
                    parse_msg(buf,len);
                }
            }
        }
    }

    return 0;
}

int main(void)
{
    const char *devname="/dev/ttyUSB0";
    int fd = 0;
    long baud = 115200;

    fd = open(devname, O_RDONLY);
    if (fd < 0)
    {
        printf("[ERROR] uart [%s] open file failed .", devname);
        return -1;
    }

    set_port_attr(fd, baud, 8, "N", '1', 0, 0);
    printf("uart [%s] open sucess,baud=%ld bps.\n", devname, baud);
    loop_read(fd);

    close(fd);
    printf("Quit main program.\n");
    return 0;
}