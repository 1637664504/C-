#include <iostream>
#include <string>
#include <map>
# include <functional>
using namespace std;

class MyClass
{
private:

public:
    // 创建映射
    std::map<std::string, std::function<int(char*)>> fun_map;

    MyClass()
    {
        fun_map["clean"] = bind(&MyClass::handler_clean, *this, std::placeholders::_1);
        fun_map["version"] = bind(&MyClass::handler_version, *this, std::placeholders::_1);
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

int main(void)
{
    MyClass a;

    char buf[16] = "123456abc";
    a.fun_map["clean"](buf);

    // c++11 遍历
    for (auto it: a.fun_map)
    {
        it.second(buf);
    }

    return 0;
}

/*
clean:123456abc
clean:123456abc
version:123456abc

 */