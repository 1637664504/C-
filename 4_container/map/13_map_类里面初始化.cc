#include <iostream>
#include <string>
#include <map>
using namespace std;

// 定义一个函数指针
typedef int (*handler_cmd_fun)(char* cmd);
class Cmd {
private:
    map<string, handler_cmd_fun> cmd_fun;
    map<string, string> map_test;

public:
    Cmd()
    {
        cmd_fun = {
            {"wifi",handler_wifi},
            {"version",handler_version},
        };
        // cmd_fun.insert(pair <string, handler_cmd_fun>("wifi", handler_wifi));
        map_test = {
            {"123","abc"},
        };

    }

    static int handler_wifi(char* cmd)
    {
        cout << "wifi:" << cmd << endl;

        return 0;
    }

    static int handler_version(char* cmd)
    {
        cout << "version:" << cmd << endl;

        return 0;
    }
};

int main(void)
{
    char buf[16] = "1234567";
    Cmd cmd;
    return 0;
}