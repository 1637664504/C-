#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> a;
    unsigned long int i;
    //int i;
    for(i=0;i<10;i++)
    {
        a.push_back(i);
    }

    //1.遍历
    cout << a.size() << endl;
    for(i=0; i<a.size(); i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}