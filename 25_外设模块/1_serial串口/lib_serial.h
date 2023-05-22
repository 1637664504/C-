#ifndef __lib__serial__
#define __lib__serial__

// extern "C"
// {
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

static void set_baudrate(struct termios *opt, unsigned int baudrate);
static void set_data_bit(struct termios *opt, unsigned int databit);
static void set_parity(struct termios *opt, char parity);
static void set_stopbit(struct termios *opt, const char *stopbit);
int set_port_attr(
    int fd,
    int baudrate,        // B1200 B2400 B4800 B9600 .. B115200
    int databit,         // 5, 6, 7, 8
    const char *stopbit, //  "1", "1.5", "2"
    char parity,         // N(o), O(dd), E(ven)
    int vtime,
    int vmin);

// }
#endif