#include <iostream>
#include <fstream>
#include <memory>
#include <json/json.h>

// 假设我们有一个JSON字符串或文件内容
std::string json_data = R"({
    "name": "John Doe",
    "age": 30,
    "city": "New York",
    "hobbies": ["reading", "gaming"]
})";

void parse_and_modify_json()
{
    // 1.解析JSON字符串
    Json::Value root;
    Json::CharReaderBuilder builder;
    std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    JSONCPP_STRING err;
    bool parsingSuccessful = reader->parse(json_data.c_str(), json_data.c_str() + json_data.size(), &root, &err);
    if (!parsingSuccessful)
    {
        std::cout << "Failed to parse JSON: " << std::endl;
        return;
    }

    // 2.改: 修改JSON数据
    root["name"] = "Jane Doe";          // 修改名字
    root["age"] = 31;                   // 修改年龄
    root["hobbies"][0] = "programming"; // 替换第一个爱好
    // 添加新的键值对
    root["job"] = "Software Engineer";

    // 3.查
    std::string name = root["name"].asString();
    int age = root["age"].asInt();
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;

    // 4.转为string
    bool shouldUseOldWay = false;   //使用旧版本的API
    if (shouldUseOldWay)
    {
        Json::FastWriter writer;
        const std::string json_file = writer.write(root);
        std::cout <<"old way ---\n"<< json_file << std::endl;
    }
    else
    {
        Json::StreamWriterBuilder builder;
        const std::string json_file = Json::writeString(builder, root);
        std::cout <<"new way ---\n"<< json_file << std::endl;
    }

    // 5.写入文件
    std::ofstream outfile("output.json");
    if (outfile.is_open())
    {
        Json::StreamWriterBuilder builder;
        builder["commentStyle"] = "None";
        builder["indentation"] = "   "; // 增加缩进
        std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
        writer->write(root, &outfile);
    }
    outfile.close();
}

int main(void)
{
    parse_and_modify_json();
    return 0;
}