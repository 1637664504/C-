#include <iostream>
#include <string>
#include <map>
using namespace std;

// 定义一个函数指针
typedef int (*handler_cmd_fun)(char* cmd);

int handler_wifi(char* cmd)
{
    cout << "wifi:" << cmd << endl;

    return 0;
}

int handler_version(char* cmd)
{
    cout << "version:" << cmd << endl;

    return 0;
}

int main(void)
{
    map<string, handler_cmd_fun> cmd_fun = {
        {"wifi",handler_wifi},
        {"version",handler_version},
    };

    char cmd[16] = "1234567";
    for (auto it = cmd_fun.begin(); it != cmd_fun.end(); it++)
    {
        (*it).second(cmd);
    }

    // c++11 遍历
    for (auto it: cmd_fun)
    {
        it.second(cmd);
    }
    return 0;
}