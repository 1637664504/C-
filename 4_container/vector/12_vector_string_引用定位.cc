#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> my_vector = { "123","abc","hi hello","game start","vector end" };

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

    string tmp = my_vector[1];
    cout << "vector定位: " << tmp << endl;
    string& ref_tmp = my_vector[1];
    cout << "vector引用定位: " << ref_tmp << endl;

    return 0;
}
