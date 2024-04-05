#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// CRC-16/XMODEM 多项式
#define CRC16_POLY 0x1021

// CRC-16/XMODEM 计算函数
uint16_t crc16_xmodem_update(uint16_t crc, const uint8_t *data, size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        crc = crc ^ ((uint16_t)data[i] << 8);
        for (int j = 0; j < 8; ++j)
        {
            if (crc & 0x8000)
            {
                crc = (crc << 1) ^ CRC16_POLY;
            }
            else
            {
                crc <<= 1;
            }
        }
    }

    return crc;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    const char *file_path = argv[1];
    FILE *file = fopen(file_path, "rb");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    const size_t buffer_size = 4096;
    uint8_t buffer[buffer_size];
    uint16_t crc = 0;
    while (1)
    {
        size_t bytes_read = fread(buffer, 1, buffer_size, file);
        if (bytes_read == 0)
        {
            break;
        }
        crc = crc16_xmodem_update(crc, buffer, bytes_read);
    }
    fclose(file);
    printf("CRC-16/XMODEM checksum: 0x%04X\n", crc);

    return 0;
}
