// 安装 sudo apt-get install libfmt-dev
#include <fmt/format.h>
#include <iostream>

int main()
{
    int age = 25;
    double pi = 3.14159;
    std::string name = "Alice";
    std::string buf;
    // 基本格式化
    buf = fmt::format("Hello, {}! You are {} years old.", name, age);
    std::cout << buf << std::endl;

    // 浮点数精度控制
    buf = fmt::format("The value of π is approximately {:.2f}.", pi);
    std::cout << buf << std::endl;
    return 0;
}
