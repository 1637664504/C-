/*
验证:
带参数类成员,初始化

 */

#include <iostream>
#include "B.h"
using namespace std;

B::B(int x, int y, int z)
{
    c = z;
    a = new A(x, y, this);
}

void B::show_B(void)
{
    cout << c << endl;
}


A::A(int x, int y, class B *super_)
:super(super_)
{
    a = x;
    b = y;
}

void A::show_all(void)
{
    cout << a << " " << b << " " << endl;
    super->show_B();
}

int main(int argc, char **argv)
{
    B b = B(1, 2, 3);
    b.a->show_all();

    return 0;
}
