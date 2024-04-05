#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;

using json = nlohmann::json;

// 假设我们有如下JSON字符串
std::string json_data = R"({
    "name": "John Doe",
    "age": 30,
    "city": "New York",
    "hobbies": ["reading", "gaming"]
})";

void parse_and_modify_json()
{
    // 解析JSON字符串
    json j = json::parse(json_data);

    // 检查是否解析成功（在nlohmann::json中，解析失败会抛出异常）
    try
    {
        // 修改JSON数据
        j["name"] = "Jane Doe";          // 修改名字
        j["age"] = 31;                   // 更新年龄
        j["hobbies"][0] = "programming"; // 替换第一个爱好

        // 添加新的键值对
        j["job"] = "Software Engineer";

        // 将修改后的JSON重新序列化为字符串
        std::string output = j.dump(); // 默认情况下，dump会输出美观化的JSON

        // 输出修改后的JSON
        std::cout << "Modified JSON:\n"
                  << output << std::endl;

        // 或者写入到文件
        std::ofstream out_file("modified.json");
        if (out_file)
        {
            out_file << output;
            out_file.close();
        }
    }
    catch (const json::parse_error &e)
    {
        std::cerr << "Failed to parse JSON: " << e.what() << std::endl;
    }
}

int main()
{
    parse_and_modify_json();
    return 0;
}
