#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<string> apples;
    apples.push_back("Granny Smith");
    cout << apples.at(0) << endl;   // 下角标返回

    return 0;
}