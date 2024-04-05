#include <iostream>
#include <deque>

using namespace std;
int main(void)
{
    deque<int> a;
    // 增
    a.push_back(1);
    a.push_back(3);
    a.push_back(5); //[1,3,5]

    // 头部增加
    a.push_front(0); //[0,1,3,5]

    int size = a.size();    //容器数量

    //遍历
    deque<int>::iterator it;
    for(it = a.begin(); it != a.end(); it++){
        cout << *it << endl;
    }

}