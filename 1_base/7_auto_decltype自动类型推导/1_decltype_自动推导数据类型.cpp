#include<string> 
#include<iostream>
using namespace std;

int main(void)
{
    // 推导 int 类型
    int a = 2;
    decltype(a) b = 3;
    cout << b << endl;

    // 推导 string 类型
    string c = "12345678";
    decltype(c) d = "abcdefg";
    cout << d << endl;

    return 0;
}