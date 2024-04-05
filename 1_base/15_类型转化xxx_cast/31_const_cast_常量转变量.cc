#include <iostream>
using namespace std;
void fun(char *data)
{

}

int main(void)
{
    // 实例1
    string buf = "123456";
    fun(const_cast<char *>(buf.c_str()));

    // 实例2
    const char *buf2 = "hello world";
    fun(const_cast<char *>(buf2));
    return 0;
}