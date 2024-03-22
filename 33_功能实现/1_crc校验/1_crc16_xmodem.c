#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CRC-16/XMODEM初始化值
unsigned short init_crc = 0x0000;

// CRC-16/XMODEM多项式
unsigned short poly = 0x1021;

// 输入缓冲区大小
#define BUFFER_SIZE 1024

// CRC计算函数
unsigned short crc16(const char *data, int length)
{
    unsigned short crc = init_crc;
    for (int i = 0; i < length; i++)
    {
        crc ^= (unsigned short)data[i] << 8;
        for (int j = 0; j < 8; j++)
        {
            if ((crc & 0x8000))
            {
                crc = (crc << 1) ^ poly;
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}

// 读取并计算文件CRC-16/XMODEM值
unsigned short calculate_crc(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        perror("Error opening file");
        return 0;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;
    unsigned short crc = init_crc;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0)
    {
        crc = crc16(buffer, bytes_read);
    }

    fclose(file);
    return crc;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned short crc = calculate_crc(argv[1]);
    printf("CRC-16/XMODEM: 0x%04X\n", crc);

    return EXIT_SUCCESS;
}
