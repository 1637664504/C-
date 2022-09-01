#include <iostream>

using namespace std;

void test1(void)
{
	char a=0xff;
	unsigned char b=0xff;
	int c=0;
	for(int i=1;i<5;i++)
	{
		c=a+i;	//-->0		//取模计算，256取模1，336取模256+80
		c=b+i;	//-->256	
		a++;	//--> 0
		b++;	//--> 0
	}
}
/*
gdb测试结果:
c=0;
c=256;
	--> 0x00
	--> 0x00
即1字节溢出之后, 从0计数
*/

void test2(void)
{
	int a=0xffffffff;
	unsigned int b=0xffffffff;	//取模计算
	int c=0;
	int i=1;
	//for(i=1;i<5;i++)
	{
		c=a+i;	//-->0
		c=b+i;	//-->0
		a++;	//--> 0
		b++;	//--> 0
	}
}
/*
gdb测试结果:
即1字节溢出之后, 从0计数
*/

int main(void)
{
	test1();
	test2();

    return 0;
}
