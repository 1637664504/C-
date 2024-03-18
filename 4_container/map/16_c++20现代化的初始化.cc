#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    map<string, string> a = {{"gg", "lili"}, {"mm", "ailisi"}};
    string key, value;
    for (auto &it : a)
    {
        cout << "key: " << it.first << " value: " << it.second << endl;
    }

    return 0;
}