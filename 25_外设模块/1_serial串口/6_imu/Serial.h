#include <stdint.h>

#ifndef __Serial__h
#define __Serial__h
#pragma once
class Serial
{
public:
    ~Serial();
    int open_serial(const char *serial_name, uint32_t bps);
    void close_serial(void);
    uint16_t read_serial(char *buf,uint8_t len);
    // 获取串口fd 文件描述符
    int get_serial_fd(void);
    // 设置串口参数
    int set_opt(int nSpeed, int nBits, char nEvent, int nStop);
private:
    char serial_name[64];
    int serial_fd;
    uint32_t bps;
};

#endif