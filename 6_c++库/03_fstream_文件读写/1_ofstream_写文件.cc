#include <iostream>
#include <fstream>

int main()
{
    // 创建一个 ofstream 对象，用于写入数据
    std::ofstream output_file("output.txt");

    // 检查文件是否成功打开
    if (!output_file.is_open())
    {
        std::cerr << "Error: Unable to open the file." << std::endl;
        return 1;
    }

    // 将数据写入文件
    output_file << "Hello, World!" << std::endl;
    output_file << "This is a sample text." << std::endl;

    // 关闭文件
    output_file.close();
    std::cout << "Data has been written to the file." << std::endl;

    return 0;
}

/* Running:
# cat output.txt
Hello, World!
This is a sample text.

 */