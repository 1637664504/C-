#include <iostream>
#include <sstream>

int main() {
    int a = 10;
    int b = 20;

    std::stringstream ss;
    ss << "The sum of " << a << " and " << b << " is " << (a + b) << ".";
    std::string result = ss.str();

    std::cout << result << std::endl; // 输出 "The sum of 10 and 20 is 30."

    return 0;
}

/* 运行结果
The sum of 10 and 20 is 30.
 */