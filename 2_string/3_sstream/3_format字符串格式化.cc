#include <iostream> // std::cout
#include <format>
using namespace std;

int main()
{
    std::string result = std::format("Hello, {}!", "World");
    cout << result << std::endl;
    return 0;
}