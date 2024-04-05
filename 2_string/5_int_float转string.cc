#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int a = 22;
    string str = "int a=" + to_string(a);
    cout << str << endl;

    double b = 3.1415;
    string str_double = "double b=" + to_string(b);
    cout << str_double << endl;

    return 0;
}

/* 运行结果
int a=22
double b=3.141500

 */