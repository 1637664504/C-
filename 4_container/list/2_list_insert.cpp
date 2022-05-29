#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(void)
{
    list<int> a;
    int i;
    for(i=0;i<=5;i++)
    {
        a.push_back(i);
    }

    //insert
    list<int>::iterator it;
    it = a.begin();
    it++;
    a.insert(it,11);
    a.insert(it,12);

    //insert
    vector<int> vec(2,22);
    a.insert(it,vec.begin(),vec.end());

    //遍历
    for(it = a.begin(); it != a.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
