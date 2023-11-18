#include <iostream>
#include <string>
#include <stdint.h>
using namespace std;
/*
现代c++语言, 指针为nullptr
*/

int main(void)
{
    // int a = nullptr; //编译错误
    int *b = nullptr;   //现代c++语言, 指针为nullptr
    int c = NULL;       //警告 : converting to non-pointer type 'int' from NUL

    return 0;
}
