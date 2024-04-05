#include <iostream>
#include <vector>
#include <map>
using namespace std;

/* 类似python语言，更加简洁的遍历
 */

int main(void)
{
    // 实例1
    vector<int> num = {1, 2, 3, 4, 5};
    for (int i : num)
    {
        cout << i << endl;
    }

    // 实例2
    map<int, string> numMap = {
        {1, "lili"},
        {2, "malike"},
        {3, "game"},
    };
    for (auto [key, val] : numMap)
    {
        cout << key << ": " << val << endl;
    }

    return 0;
}
