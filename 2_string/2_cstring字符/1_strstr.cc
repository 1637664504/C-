#include <iostream>
#include <string>
// #include <cstring>
#include <string.h>
using namespace std;

int main()
{
    char str1[] = "abcdefg";
    char str2[] = "cde";
    char* p1 = strstr(str1, str2);
    cout << p1 << endl;                    //输出str2在str1中第一次出现的位置开始以后的所有字符
    cout << (p1 - str1) << endl;           //输出str2在str1中第一次出现的位置

    string str3 = "abcdefgdas";
    string str4 = "efg";
    const char* p2 = strstr(str3.c_str(), str4.c_str());
    cout << p2 - str3.c_str() << endl;      //输出str4在str3中第一次出现的位置
    return 0;
}
