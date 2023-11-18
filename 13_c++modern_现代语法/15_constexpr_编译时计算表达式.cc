#include <iostream>
#include <vector>
using namespace std;

/* 编译时，计算结果
== C语言宏
 */
constexpr int test_add(int a, int b)
{
    return a+b;
}

int main(void)
{
    int num[test_add(2,3)]={0};

    return 0;
}
