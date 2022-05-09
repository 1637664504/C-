#include <iostream>

using namespace std;

int main(void)
{
    char c;
    int a;
    long b;
    long long d;
    cout << "char size=" << sizeof(c) << endl;
    cout << "int size=" << sizeof(a) << endl;
    cout << "long =" << sizeof(b) << endl;
    cout << "long long =" << sizeof(d) << endl;

    return 0;
}