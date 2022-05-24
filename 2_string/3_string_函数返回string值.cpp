#include <iostream>
#include <string>
using namespace std;

string fun_return_string()
{
    string val = "bbb";
/*
    string值返回：是从函数返回字符串对象的首选方法。
    因为 std::string 类有 move 构造函数，所以即使是长字符串，通过值返回也是高效的。
    如果一个对象有一个 move 构造函数，那么它就被称为具有移动语义的特性。
    移动语义意味着在函数返回时，对象不会被复制到不同的位置，因此，提供更快的函数执行时间。
*/
    return val;
}

int main(void)
{
    string str ="aaa";
    cout << "修改前 " << str <<endl;

    str = fun_return_string();
    cout << "修改后 " << str <<endl;

    return 0;
}