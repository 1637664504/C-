#include <iostream>
#include <vector>
using namespace std;

void show_vector(vector<int> &a)
{
    //iterator 遍历
    vector<int>::iterator it;
    for(it=a.begin(); it<a.end(); it++)
    {
        cout << *it <<endl;
    }
}

int main(void)
{
    // 1.数组转换vector
    int arr[] = { 1,2,3,4,5 };
    vector<int> a(arr, arr + 5);
    show_vector(a);

    // 2.数组转换vector -- 获取数组长度
    // int arr[] = { 1,2,3,4,5 };
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    vector<int> b(arr, arr + arr_len);
    show_vector(b);

    return 0;
}

/*
1
2
3
4
5

1
2
3
4
5

*/