#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    string file_name = "output.txt";
    if (argc == 2)
    {
        file_name = argv[1];
    }
    // 创建一个 ifstream 对象，用于读取数据
    std::ifstream input_file(file_name);

    // 检查文件是否成功打开
    if (!input_file.is_open())
    {
        std::cerr << "Error: Unable to open the file: "<< file_name << std::endl;
        return 1;
    }

    // 从文件中读取数据
    std::string line;
    while (std::getline(input_file, line))
    {
        std::cout << line << std::endl;
    }

    // 关闭文件
    input_file.close();

    return 0;
}