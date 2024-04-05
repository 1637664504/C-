#include <iostream>
using namespace std;

// 函数定义
void point_2_ref(int& x)
{
    x = 111;
    cout << "x=" << x << endl;
    return;
}

int main()
{
    int a = 100;
    int* b = &a;
    int c = *b;
    point_2_ref(*b);

    cout << "a=" << a << endl;
    cout << "b=" << *b << endl;
    cout << "c=" << c << endl;

    return 0;
}

/* 结果:
x=111
a=111
b=111
c=100

gdb查看内存
a=0x7fffffffdbe8
*b=0x7fffffffdbe8
c=0x7fffffffdbdc
x=0x7fffffffdbe8

结论: 指针转引用, 传递参数有效
*/