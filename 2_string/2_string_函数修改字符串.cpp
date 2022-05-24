#include <iostream>
#include <string>
using namespace std;

/*
reference 表示引用
1. src 的内存地址指向 str地址
    -->即string &src 是地址
    ---> 但使用 src 时，相当于使用str变量
*/
void fun_change_string(string &src)
{
    src = "bbb";
}

int main(void)
{
    string str ="aaa";
    cout << "修改前 " << str <<endl;

    fun_change_string(str);
    cout << "修改后 " << str <<endl;

    return 0;
}