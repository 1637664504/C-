#include <iostream>
#include <list>
using namespace std;

int main(void)
{
    list<int> a;

    //追加
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    //删除末尾
    a.pop_back();

    //开头添加
    a.push_front(3);
    //开头删除
    a.pop_front();

    //遍历
    list<int>::iterator it;
    for(it = a.begin(); it != a.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
