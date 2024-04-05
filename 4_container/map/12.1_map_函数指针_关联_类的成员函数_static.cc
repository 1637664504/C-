#include <iostream>
#include <string>
#include <map>
using namespace std;

// 定义一个函数指针
typedef int (*handler_cmd_fun)(void* Self, char* cmd);

class Class_A
{
private:

public:
    map<string, handler_cmd_fun> cmd_fun;

    Class_A()
    {

    }

    void init_funtion()
    {
        cmd_fun = {
        {"clean",handler_clean},
        {"version",handler_version},
        };
    }

    static int handler_clean(void* Self, char* cmd)
    {
        Class_A* self = (Class_A*)Self;
        self->test(11);
        cout << "clean:" << cmd << endl;

        return 0;
    }

    static int handler_version(void* Self, char* cmd)
    {
        Class_A* self = (Class_A*)Self;
        self->test(22);
        cout << "version:" << cmd << endl;

        return 0;
    }

    void test(int cmd)
    {
        cout << "test " << cmd << endl;
    }
};


int main(void)
{
    Class_A a;
    a.init_funtion();

    char cmd[16] = "1234567";
    // c++11 遍历
    for (auto it : a.cmd_fun)
    {
        it.second(&a, cmd);
    }

    // 主动调用
    char buf[16] = "aabbcc";
    a.cmd_fun["clean"](&a, buf);

    return 0;
}

/*
test 11
clean:1234567
test 22
version:1234567
test 11
clean:aabbcc
 */