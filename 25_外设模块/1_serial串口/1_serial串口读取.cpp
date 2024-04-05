#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SERIAL_PORT "/dev/ttyUSB0"
int main(int argc, char **argv)
{
    int fd = open(SERIAL_PORT, O_RDWR);
    if (fd < 0){
        perror("open serial port failed");
        return 1;
    }

    char buf[1024];
    while (1){
        ssize_t n = read(fd, buf, sizeof(buf));
        if (n < 0){
            perror("read serial port failed");
            return 1;
        }
        if (n == 0){
            break;
        }
        printf("%ld: \n", n);
        sleep(1);
        // write(1, buf, n);
    }
    return 0;
}