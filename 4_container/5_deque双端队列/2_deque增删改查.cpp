#include <iostream>
#include <deque>

using namespace std;

void del(deque<int> &a)
{
    // del尾
    a.pop_back(); //[0,1,3]

    // del 头
    a.pop_front(); //[1,3]
    a.clear();
}

void add(deque<int> &a)
{
    // 增
    a.push_back(1);
    a.push_back(3);
    a.push_back(5); //[1,3,5]

    // 头部增加
    a.push_front(0); //[0,1,3,5]
}

void change(deque<int> &a)
{
    deque<int>::iterator it_begin,it_end,it_rbegin;
    it_begin = a.begin();
    it_end = a.end();
    it_rbegin = a.rbegin();
    cout<< *it_begin << " " << *it_end << endl;
}

int main(void)
{
    deque<int> a;

    add(a);
    change(a);
    del(a);

    //遍历
    deque<int>::iterator it;
    for(it = a.begin(); it != a.end(); it++){
        cout << *it << endl;
    }

}