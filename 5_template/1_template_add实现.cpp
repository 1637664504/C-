/*
模板 add()
*/
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b)
{
    return a+b;
}

int main(void)
{
    int a=2,b=3;
    int c = 0;
    c = add(a, b);
    cout << "int " << c << endl;

    double x=3.1415926, y=0.56789;
    double z = 0.0;
    z = add(x,y);
    cout << "double " << z << endl;
    return 0;
}