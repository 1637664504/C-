#include "add.h"
#include "sub.h"
#include <iostream>
using namespace std;

int main()
{
    int c = add(1, 2);
    cout <<"add: " << c << endl;

    c = sub(5,3);
    cout << "sub: " << c << endl;

    return 0;
}

/* nm查看符号表
nm add.o
0000000000000000 T add

nm sub.o
0000000000000000 T _Z3subii  # sub函数, ii表示参数
 */


/* nm 可读形式的符号表
nm -C -g add.o
0000000000000000 T add

nm -C -g sub.o
0000000000000000 T sub(int, int)
 */