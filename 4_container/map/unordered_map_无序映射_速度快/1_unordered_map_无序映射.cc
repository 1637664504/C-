#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
    unordered_map<int, int> my_map = {
        {1, 115566},
        {2, 220033},
    };
    int value;

    // 查找元素
    if (my_map.find(1) != my_map.end())
    {
        value = my_map[1];
        cout << "Value for key 1: " << value << endl;
    }
    else
    {
        cout << "Key 1 not found" << endl;
    }

    // 删除元素
    my_map.erase(1);

    // 遍历map中的元素
    for (auto &it : my_map)
    {
        cout << "Key: " << it.first << ", Value: " << it.second << endl;
    }

    return 0;
}
