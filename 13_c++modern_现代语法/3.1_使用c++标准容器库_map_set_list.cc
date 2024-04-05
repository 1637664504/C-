#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main(void)
{
    map<string, string> a = {{"gg","lili"}, {"mm", "ailisi"}};
    string key, value;
    for (auto &it : a)
    {
        cout << "key: " << it.first << " value: " << it.second << endl;
    }

    // unordered_map<int, string> a = {11 : "lili", 12 : "zero", 13 : "Malike", 14 : "ailisi"};
    // for (auto &it : a)
    // {
    //     cout << "key: " << it.first << " value: " << it.second << endl;
    // }

    return 0;
}