#include <iostream>
#include <stdio.h>
#include <stdint.h>
using namespace std;

void test_char_to_reference(char &buf[])
{
    snprintf(buf, sizeof(buf), "hello %s to here", "lili");
}

int main()
{
    char buf[32];
    cout << buf << endl;
    return 0;
}

/*结果
编译错误

*/
