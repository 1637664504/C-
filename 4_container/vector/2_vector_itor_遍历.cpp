#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> a;
    unsigned long int i;
    for(i=0;i<10;i++)
    {
        a.push_back(i);
    }

    //iterator 遍历
    vector<int>::iterator it;
    for(it=a.begin(); it<a.end(); it++)
    {
        cout << *it <<endl;
    }

    return 0;
}