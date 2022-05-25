/*
模板 add()
*/
#include <iostream>
using namespace std;

template <typename T>
void my_swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

int main(void)
{
    int a=2,b=3;
    my_swap(a, b);
    cout << "a="<<a<<" b="<<b<< endl;


    double x=3.1415926, y=0.56789;
    my_swap(x,y);
    cout << "x=" <<x << " ,y="<<y<< endl;

    return 0;
}