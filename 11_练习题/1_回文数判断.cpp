#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int getEvery10baseNum(unsigned char b[],int blen,int num)
{
    int i = 0;
    int big;
    int small;
    while ((big=(num / pow(10, i))) != 0)
    {
        small = (num / pow(10, i+1));
        small *= 10;
        b[i]=big - small;;
        i++;
        if(i>=blen)
            break;
    }

    return i;
}

int isPalindromeNumber(int num)
{
    unsigned char b[256];
    int len = 0;
    int ret = 1;
    len = getEvery10baseNum(b,256,num);
    if(len > 1)
    {
        int i;
        for(i=0;i<=(len/2);i++)
        {
            
            if(b[i] != b[len-i-1])
            {
                cout << b[i] << "!=" << b[len-i-1] << endl;
                printf("b[i] %u != b[len-i-1] %u\n",b[i],b[len-i-1] );
                ret = 0;
                break;
            }
            cout << b[i] << "==" << b[len-i-1] << endl;
            printf("b[i] %u == b[len-i-1] %u\n",b[i],b[len-i-1] );
        }
    }

    return ret;
}

int main(void)
{
    isPalindromeNumber(54321);
    isPalindromeNumber(123321);
    isPalindromeNumber(12321);
    return 0;
}