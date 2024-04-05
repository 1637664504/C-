#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> my_vector = { 1, 2, 3, 4, 5 };

    // 获取vector中元素的数量
    int size = my_vector.size();

    // 定位第一个元素
    cout << "First element: " << my_vector[0] << endl;

    // 定位中间元素
    int middle = size / 2;
    cout << "Middle element: " << my_vector[middle] << endl;

    // 定位最后一个元素
    cout << "Last element: " << my_vector[size - 1] << endl;

    // 定位不存在的元素
    cout << "Element at position 100: " << my_vector[100] << endl;

    return 0;
}
