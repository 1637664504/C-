#include <stdio.h>
#include <string.h>
#include <stdint.h>
/*CRC-16 CCITT*/
// CCITT: x^16 + x^12 + x^5 + x^0 (0x1021)
/*高位在左低位在右，使用时请注意高低位顺序！！！*/
unsigned short CRC16_CCITT (unsigned char *pdata, int len)
{
	unsigned short crc=0x0000;//初始值 
	int i, j;
	for ( j=0; j<len;j++)
	{
		crc^=pdata[j];

		for (i=0; i<8; i++){
			if( (crc&0x0001) >0){
				crc = (crc >> 1) ^ 0x8408;//0x1021 翻转  0x8408
			}else
				crc >>= 1;
		}
	}
	return crc;
}

// int main(int argc, char **argv)
// {
//     unsigned short crc;
//     // unsigned char pdata;
//     int len;

//     // pdata = (unsigned char *)argv[1];
//     // len = strlen(argv[1]);

//     unsigned char pdata[6]={'1','2','3','4','5','6'};
//     crc = CRC16_CCITT(pdata, 6);

//     printf("CRC-16 CCITT: 0x%04x\n", crc);

//     return 0;
// }
