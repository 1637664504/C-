#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#define DEV_NAME "/dev/ttyUSB0"
int main(int argc, char *argv[])
{
    int fd;
    int len, i, ret;
    char buf[] = "hello world!";
    fd = open(DEV_NAME, O_RDWR | O_NOCTTY);
    if (fd < 0)
    {
        perror(DEV_NAME);
        return -1;
    }
    struct termios uart_cfg_opt;
    speed_t speed = B115200;
    if (-1 == tcgetattr(fd, &uart_cfg_opt))
        return -1;
    tcflush(fd, TCIOFLUSH);
    cfsetospeed(&uart_cfg_opt, speed);
    cfsetispeed(&uart_cfg_opt, speed);
    if (-1 == tcsetattr(fd, TCSANOW, &uart_cfg_opt))
        return -1;
    uart_cfg_opt.c_cc[VTIME] = 1;
    uart_cfg_opt.c_cc[VMIN] = 0;
    /* Data length setting section */ uart_cfg_opt.c_cflag &= ~CSIZE;
    uart_cfg_opt.c_cflag |= CS8;
    uart_cfg_opt.c_iflag &= ~INPCK;
    uart_cfg_opt.c_cflag &= ~PARODD;
    uart_cfg_opt.c_cflag &= ~CSTOPB;
    /* Using raw data mode */
    uart_cfg_opt.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    uart_cfg_opt.c_iflag &= ~(INLCR | IGNCR | ICRNL | IXON | IXOFF);
    uart_cfg_opt.c_oflag &= ~(INLCR | IGNCR | ICRNL);
    uart_cfg_opt.c_oflag &= ~(ONLCR | OCRNL);
    /* Apply new settings */
    if (-1 == tcsetattr(fd, TCSANOW, &uart_cfg_opt))
        return -1;
    tcflush(fd, TCIOFLUSH);

    len = write(fd, buf, sizeof(buf)); /* 向串口写入字符串 */
    if (len < 0)
    {
        printf("write data error \n");
    }
    while(1){
        len = read(fd, buf, sizeof(buf)); /* 在串口读入字符串 */
        if (len < 0)
        {
            printf("read error \n");
            return -1;
        }
        else if (len == 0)
            printf("read 0 \n");
        else{
            printf("len=%d,buf=%s\n",len,buf);
        }
    }
    printf("%s", buf); /* 打印从串口读出的字符串 */
    return (0);
}