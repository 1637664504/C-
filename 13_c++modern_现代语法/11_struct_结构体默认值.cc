#include <iostream>
#include <string>
#include <stdint.h>
using namespace std;
/* 
现代c++ 语法, 定义变量初始化
*/
struct A{
    string name="lilisi";
    int32_t age=18;
    uint32_t hight=170;
    float weight=50.0;
};

int main(void)
{
    struct A a;

    return 0;
}
/* gdb 调试结果

name:"lilisi"
age:18
hight:170
weight:50
*/