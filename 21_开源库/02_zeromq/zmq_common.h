#pragma once
#include <stdint.h>

struct zmq_data{
    uint8_t type;
    uint8_t len;
    uint8_t count;
    uint8_t idx;
    char name[32];
};
