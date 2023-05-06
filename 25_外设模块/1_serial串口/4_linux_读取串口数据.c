#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

/**
 * @brief set_baudrate  设置波特率
 * @param opt
 * @param baudrate
 */
static void set_baudrate(struct termios *opt, unsigned int baudrate)
{
    cfsetispeed(opt, baudrate);
    cfsetospeed(opt, baudrate);
}

/**
 * @brief set_data_bit  设置数据位
 * @param opt
 * @param databit
 */
static void set_data_bit(struct termios *opt, unsigned int databit)
{
    opt->c_cflag &= ~CSIZE;
    switch (databit)
    {
    case 8:
        opt->c_cflag |= CS8;
        break;
    case 7:
        opt->c_cflag |= CS7;
        break;
    case 6:
        opt->c_cflag |= CS6;
        break;
    case 5:
        opt->c_cflag |= CS5;
        break;
    default:
        opt->c_cflag |= CS8;
        break;
    }
}

/**
 * @brief set_parity  设置奇偶校验位
 * @param opt
 * @param parity
 */
static void set_parity(struct termios *opt, char parity)
{
    switch (parity)
    {
    case 'N': /* no parity check */
        opt->c_cflag &= ~PARENB;
        break;
    case 'E': /* even */
        opt->c_cflag |= PARENB;
        opt->c_cflag &= ~PARODD;
        break;
    case 'O': /* odd */
        opt->c_cflag |= PARENB;
        opt->c_cflag |= ~PARODD;
        break;
    default: /* no parity check */
        opt->c_cflag &= ~PARENB;
        break;
    }
}

/**
 * @brief set_stopbit   设置停止位
 * @param opt
 * @param stopbit
 */
static void set_stopbit(struct termios *opt, const char *stopbit)
{
    if (0 == strcmp(stopbit, "1"))
    {
        opt->c_cflag &= ~CSTOPB; /* 1 stop bit */
    }
    else if (0 == strcmp(stopbit, "1"))
    {
        opt->c_cflag &= ~CSTOPB; /* 1.5 stop bit */
    }
    else if (0 == strcmp(stopbit, "2"))
    {
        opt->c_cflag |= CSTOPB; /* 2 stop bits */
    }
    else
    {
        opt->c_cflag &= ~CSTOPB; /* 1 stop bit */
    }
}

int set_port_attr(
    int fd,
    int baudrate,        // B1200 B2400 B4800 B9600 .. B115200
    int databit,         // 5, 6, 7, 8
    const char *stopbit, //  "1", "1.5", "2"
    char parity,         // N(o), O(dd), E(ven)
    int vtime,
    int vmin)
{
    struct termios opt;
    tcgetattr(fd, &opt);
    // 设置波特率
    set_baudrate(&opt, baudrate);
    opt.c_cflag |= CLOCAL | CREAD; /* | CRTSCTS */
    // 设置数据位
    set_data_bit(&opt, databit);
    // 设置校验位
    set_parity(&opt, parity);
    // 设置停止位
    set_stopbit(&opt, stopbit);
    // 其它设置
    opt.c_oflag = 0;
    opt.c_lflag |= 0;
    opt.c_oflag &= ~OPOST;
    opt.c_cc[VTIME] = vtime;
    opt.c_cc[VMIN] = vmin;
    tcflush(fd, TCIFLUSH);
    return (tcsetattr(fd, TCSANOW, &opt));
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

int parse_msg(uint8_t *msg, uint8_t len)
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

    printf("温度%d 气压%f 时间%u \n", data->tempertaure, data->pa, data->time);
    printf("加速度 %f %f %f \n", data->accelerometer_x, data->accelerometer_y, data->accelerometer_z);
    printf("角速度 %f %f %f \n", data->gyroscope_x, data->gyroscope_y, data->gyroscope_z);
    printf("欧拉角 roll %f, pitch %f, yaw %f \n", data->roll, data->pitch, data->yaw);
    printf("四元组 %f %f %f %f \n", data->quaternion_w, data->quaternion_x, data->quaternion_y, data->quaternion_z);


    return 0;
}

int main(int argc, char **argv)
{

    printf("=========BuildTime:[%s %s]============\n", __DATE__, __TIME__);

    // 通过指令 ls /dev/* 查看电脑硬件设备
    // 一般 ttyS0 等价于Windows的COM1 ,以此类推
    // 可用MobaXterm软件在Windows下运行linux程序

    char *devPath = "/dev/ttyUSB0";
    int fd = 0;
    long baud = 115200;

    fd = open(devPath, O_RDONLY);
    if (fd < 0)
    {
        printf("[ERROR] uart [%s] open file failed .", devPath);
        return -1;
    }

    set_port_attr(fd, baud, 8, "N", '1', 0, 0);
    printf("uart [%s] open sucess,baud=%ld bps.\n", devPath, baud);

    uint8_t buf[1024];
    int max_size = sizeof(buf);
    int len = 0;
    while (1) // Ctrl+C 结束终端
    {
        memset(buf, 0, max_size);
        len = read(fd, buf, max_size);
        if (len <= 0)
        {
            usleep(1000);
            continue;
        }
        printf("Length:%d\n", len);
        parse_msg(buf, len);
    }

    close(fd);
    printf("Quit main program.\n");

    return 0;
}