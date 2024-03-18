#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    map<string, string> a = {"gg" : "lili", "dd" : "zero", "bb" : "Malike", "mama" : "ailisi", "jj" : "123", "kk" : "234"};
    string key, value;
    for (auto &it : a)
    {
        key = it.first;
        value = it.second;
    }

    return 0;
}