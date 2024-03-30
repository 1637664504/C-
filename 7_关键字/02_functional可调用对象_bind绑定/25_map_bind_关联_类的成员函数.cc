#include <iostream>
#include <string>
#include <map>
# include <functional>
using namespace std;

class MyClass
{
private:

public:
    MyClass()
    {
    }

    int handler_clean(char* cmd)
    {
        cout << "clean:" << cmd << endl;

        return 0;
    }

    int handler_version(char* cmd)
    {
        cout << "version:" << cmd << endl;

        return 0;
    }

    void foo()
    {
        cout << "foo" << endl;
    }
};

// 创建映射
std::map<std::string, std::function<int(char *)>> fun_map;

int main(void)
{
    MyClass a;
    fun_map["clean"] = bind(&MyClass::handler_clean, a, std::placeholders::_1);
    fun_map["version"] = bind(&MyClass::handler_version, a, std::placeholders::_1);

    char buf[16] = "123456abc";
    fun_map["clean"](buf);

    return 0;
}