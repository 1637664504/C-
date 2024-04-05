#include <iostream>
#include <format>

int main(void)
{
    std::string format_str = std::format("There are {} fools in the world", 10);
    std::cout << format_str << std::endl;

    return 0;
}
/*
编译不通过,提示服务找到 format
 */