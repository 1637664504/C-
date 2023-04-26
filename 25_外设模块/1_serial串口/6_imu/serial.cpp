#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>
#include <termios.h>

/* 
串口打开 opern_serial(串口名,波特率) 
串口关闭 close_serial()
设置串口属性 set_opt(nSpeed, int nBits, char nEvent, int nStop) 
    默认值:
        波特率 115200
        数据位 8
        奇偶校验 n
        停止位 1
获取串口文件描述符 get_serial_fd()
    用户使用select监听 fd
 */

class serial
{
public:
    int open_serial(const char *serial_name, uint32_t bps = 115200)
    {
        if (serial_name == NULL)
            return -1;
        int fd = open(serial_name, O_RDWR | O_NOCTTY | O_NDELAY);
        if (-1 == fd)
        {
            perror("Can't Open Serial Port");
            return (-1);
        }

        /*恢复串口为阻塞状态*/
        if (fcntl(fd, F_SETFL, 0) < 0)
            printf("fcntl failed!\n");
        else
            printf("fcntl=%d\n", fcntl(fd, F_SETFL, 0));
        /*测试是否为终端设备*/
        if (isatty(STDIN_FILENO) == 0)
            printf("standard input is not a terminal device\n");
        else
            printf("isatty success!\n");
        printf("串口文件打开成功......\n");
        this->serial_fd = fd;
        this->set_opt(fd, bps);

        return 0;
    }

    ~serial()
    {
        if (this->serial_fd > 0)
            this->close_serial();
    }

    void close_serial()
    {
        close(this->serial_fd);
        this->serial_fd = -1;
    }

    uint16_t read_serial(char *buf,uint8_t len)
    {
        uint16_t ret = 0;
        // TODO: 实现阻塞读取串口数据
        return ret;
    }

    // 获取串口fd 文件描述符
    int get_serial_fd(void)
    {
        return this->serial_fd;
    }

    // 设置串口参数
    int set_opt(int nSpeed = 115200, int nBits = 8, char nEvent = 'n', int nStop = 1) // 115200 8 n 1
    {
        struct termios newtio, oldtio;
        fd = this->serial_fd;
        /*保存测试现有串口参数设置，在这里如果串口号等出错，会有相关的出错信息*/
        if (tcgetattr(fd, &oldtio) != 0)
        {
            perror("SetupSerial 1");
            printf("tcgetattr( fd,&oldtio) -> %d\n", tcgetattr(fd, &oldtio));
            return -1;
        }
        bzero(&newtio, sizeof(newtio));
        /*步骤一，设置字符大小*/
        newtio.c_cflag |= CLOCAL | CREAD;
        newtio.c_cflag &= ~CSIZE;
        /*设置停止位*/
        switch (nBits)
        {
        case 7:
            newtio.c_cflag |= CS7;
            break;
        case 8:
            newtio.c_cflag |= CS8;
            break;
        }
        /*设置奇偶校验位*/
        switch (nEvent)
        {
        case 'o':
        case 'O': // 奇数
            newtio.c_cflag |= PARENB;
            newtio.c_cflag |= PARODD;
            newtio.c_iflag |= (INPCK | ISTRIP);
            break;
        case 'e':
        case 'E': // 偶数
            newtio.c_iflag |= (INPCK | ISTRIP);
            newtio.c_cflag |= PARENB;
            newtio.c_cflag &= ~PARODD;
            break;
        case 'n':
        case 'N': // 无奇偶校验位
            newtio.c_cflag &= ~PARENB;
            break;
        default:
            break;
        }
        /*设置波特率*/
        switch (nSpeed)
        {
        case 2400:
            cfsetispeed(&newtio, B2400);
            cfsetospeed(&newtio, B2400);
            break;
        case 4800:
            cfsetispeed(&newtio, B4800);
            cfsetospeed(&newtio, B4800);
            break;
        case 9600:
            cfsetispeed(&newtio, B9600);
            cfsetospeed(&newtio, B9600);
            break;
        case 115200:
            cfsetispeed(&newtio, B115200);
            cfsetospeed(&newtio, B115200);
            break;
        case 460800:
            cfsetispeed(&newtio, B460800);
            cfsetospeed(&newtio, B460800);
            break;
        default:
            cfsetispeed(&newtio, B9600);
            cfsetospeed(&newtio, B9600);
            break;
        }
        /*设置停止位*/
        if (nStop == 1)
            newtio.c_cflag &= ~CSTOPB;
        else if (nStop == 2)
            newtio.c_cflag |= CSTOPB;
        /*设置等待时间和最小接收字符*/
        newtio.c_cc[VTIME] = 0;
        newtio.c_cc[VMIN] = 0;
        /*处理未接收字符*/
        tcflush(fd, TCIFLUSH);
        /*激活新配置*/
        if ((tcsetattr(fd, TCSANOW, &newtio)) != 0)
        {
            perror("com set error");
            return -1;
        }
        printf("#@ 串口设置成功......\n");
        return 0;
    }

private:
    char serial_name[64];
    int serial_fd;
    uint32_t bps;
};