#include <iostream>
#include <string>

int main(int argc, const char* argv[])
{
    // 截取字符后8位
    std::string str = "123456789";
    std::string last_8_chars = str.substr(str.length() - 8);

    std::cout << "Last 8 characters: " << last_8_chars << std::endl;

    return 0;
}

/*
Last 8 characters: 23456789
 */