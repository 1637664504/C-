#include <iostream>
#include <climits>
using namespace std;

int main(int argc, char **argv)
{
    long int x,y;
    while(1){
        cout << "please input x,y" << endl;
        cin >> x >> y;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cout << "不合法的输入，请重新输入: ";
            continue;
        }
    }
}

/* 
参考: https://cloud.tencent.com/developer/article/1360093
清空 cin 缓冲区

 */