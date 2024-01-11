#include <iostream>
#include <string>
#include <map>
using namespace std;

int handler_wifi(const char* cmd)
{
    cout << "wifi:" << cmd << endl;

    return 0;
}

int main(void)
{
    map<string, string> cmd_opt;
    cmd_opt["wifi"] = "handler_wifi";

    for (auto it = cmd_opt.begin(); it != cmd_opt.end(); it++)
    {
        cout << (*it).first << ": " << (*it).second << endl;
    }
    return 0;
}