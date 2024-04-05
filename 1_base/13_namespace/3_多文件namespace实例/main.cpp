
/* 
多文件引用实例
add.cpp
main.cpp

 */
#include "add.h"
int main(void)
{
    integer::a = 10;            // 引用namespace 变量
    integer::fun_test();        // 引用namespace 函数

    return 0;
}

/* 
result:

integer test
 */