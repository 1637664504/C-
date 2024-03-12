/* 
验证:
带参数类成员,初始化

 */

#include <iostream>
using namespace std;

class A{
public:
    A(int x, int y)
    {
        a=x;
        b=y;
    }

private:
    int a;
    int b;
};

class B{
public:
    B(int x,int y, int z):a(x,y)
    {
        c = z;
    }

private:
    A a;
    int c;
};

int main(int argc, char **argv)
{
    B b = B(1,2,3);

    return 0;
}

