#include <iostream>

using namespace std;

int main(void)
{
    char c;
    int a;
    long b;
    long long d;
    float e;
    double f;
    cout << "char size=" << sizeof(c) << endl;
    cout << "int size=" << sizeof(a) << endl;
    cout << "long =" << sizeof(b) << endl;
    cout << "long long =" << sizeof(d) << endl;
    cout << "float =" << sizeof(e) << endl;
    cout << "double =" << sizeof(f) << endl;

    return 0;
}

/* 运行结果
har size=1
int size=4
long =8
long long =8
float =4
double =8

 */