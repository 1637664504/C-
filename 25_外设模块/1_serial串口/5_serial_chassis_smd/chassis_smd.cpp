#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <stdint.h>
#include "chassis_smd.h"
#include "crc.h"

class Chassis_smd_impl{
private:
    int fd_serial;
    char serial_frame[64];

public:
    Chassis_smd_impl(const char *serial_port){
        this->fd_serial = open_port(serial_port);
        if (this->fd_serial < 0)
            throw "open_port failed";
        strncpy(serial_frame, serial_port, sizeof(serial_frame));
        set_opt(this->fd_serial,115200,8,'n',1);
    }

    ~Chassis_smd_impl(){
        close_port();
    }

    int open_port(const char *serial_port)
    {
        if(serial_port == NULL)
            return -1;
        int fd = open(serial_port, O_RDWR | O_NOCTTY | O_NDELAY);
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
        printf("fd-open=%d\n", fd);
        printf("串口文件打开成功......\n");

        return fd;
    }

    void close_port(){
        close(this->fd_serial);
    }

    // 设置串口参数
    int set_opt(int fd, int nSpeed, int nBits, char nEvent, int nStop) // 115200 8 n 1
    {
        struct termios newtio, oldtio;
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

    void help(){
        const char *info="\
	w		# w前进 \n\
a	s	d	# a左转 s停止 d右转 \n\
	x		# x后退 \n\
\n\
q		e	# q左前 e右前 \n\
z		c	# z左后 c右后 \n\
Q Quit";
        printf("%s",info);
    }

    int get_fd_serial(){
        return this->fd_serial;
    }

    int ctrl_move()
    {
        char c;
        while(1)
        {
            this->help();
            c = getchar();
            putchar('\b'); // 删除回显
            printf("input: [%c]\n", c);
            if(c == 'Q')
                break;
            switch(c)
            {
                case 'w':
                    this->move_up(0.0,10.0);
                    break;
                case 's':
                    this->move_up(0.0,0.0);
                    break;
                case 'd':
                    this->move_up(10.0,10.0);
                    break;
                case 'a':
                    this->move_up(-10.0,10.0);
                    break;
                case 'x':
                    this->move_up(0.0,-10.0);
                    break;
                case 'q':
                    this->move_up(-10.0,10.0);
                    break;
                case 'e':
                    this->move_up(10.0,10.0);
                    break;
                case 'z':
                    this->move_up(-10.0,-10.0);
                    break;
                case 'c':
                    this->move_up(10.0,-10.0);
                    break;
            }
            sleep(1);
            move_stop();
        }

        return 0;
    }

    int move_up(float direction,float speed)
    {
        struct Slam_packet data;
        memset(&data,0,sizeof(data));
        data.w = direction;
        data.v = speed;

        struct serial_frame * frame;
        frame = this->pack_serial_frame(CMD_SLAM_LOCAL,NAV_ID,Vision_Slam_ID,&data,sizeof(data));
        if(frame == NULL)
        {
            perror("malloc failed");
            return -1;
        }
        write(this->fd_serial,frame,frame->length+4);
        this->show_hex((uint8_t *)frame,frame->length+4);
        free(frame);

        return 0;
    }

    void move_stop()
    {
        move_up(0.0,0.0);
    }

    struct serial_frame * pack_serial_frame(uint8_t cmd, uint8_t dst_id,uint8_t src_id,void *data,uint16_t len)
    {
        struct serial_frame *frame;
        uint16_t frame_len = len+9;
        frame = (struct serial_frame *)malloc(frame_len);
        if(frame == NULL)
            return NULL;
        memset(frame,0,sizeof(struct serial_frame));
        frame->head0 = 'R';
        frame->head1 = 'E';
        frame->length = len+5;
        frame->cmd = cmd;
        frame->dst_id = dst_id;
        frame->src_id = src_id;
        uint8_t *p_data = &(frame->src_id)+1;
        memcpy(p_data,data,len);
        uint16_t crc_16 = CRC16_CCITT((unsigned char*)frame,frame_len-2);
        void *p_crc = (uint8_t *)frame+frame_len-2;
        memcpy(p_crc, &crc_16, sizeof(crc_16));

        return frame;
    }
    void pack_serial_frame_free(struct serial_frame *pack)
    {
        if(pack)
        {
            free(pack);
            pack = NULL;
        }
    }
    void show_hex(uint8_t *buf, uint16_t len)
    {
        int i;
        for(i=0;i<len;i++)
        {
            printf("%02x ",buf[i]);
            if(i%16==15)
                printf("\n");
        }
        printf("\n");
    }
};

/* 终端输入立即生效 */
void config_input_nonlock(void)
{
    struct termios stored_settings;
    struct termios new_settings;

    tcgetattr(0, &stored_settings);
    new_settings = stored_settings;
    new_settings.c_lflag &= (~ICANON);
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &new_settings);

    // tcsetattr(0, TCSANOW, &stored_settings); // 恢复终端参数
}

int loop_read(int fd)
{
    fd_set rd_set;
    struct timeval tv;
    int ret;
    char buf[256];

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
                    buf[len] = '\0';
                    printf("len=%d,%s\n", len, buf);
                }
            }
        }
    }

    return 0;
}

int main(int argc, char **argv)
{
    const char *serial_port = "/dev/ttyUSB0";
    class Chassis_smd_impl chassis_impl = Chassis_smd_impl(serial_port);
    int fd = chassis_impl.get_fd_serial();
    // loop_read(fd);
    config_input_nonlock();
    chassis_impl.help();
    chassis_impl.ctrl_move();

    return 0;
}