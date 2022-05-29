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

    //vector插入
    a.insert(a.begin(),1);

    int b=7;
    vector<int>::iterator it;
    for(it=a.begin(); it<a.end(); it++)
    {
        if(b <= *it)
        {
            a.insert(it,b);
            break;
        }
    }

    return 0;
}