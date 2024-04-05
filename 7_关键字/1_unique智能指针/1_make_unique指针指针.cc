#include <iostream>
#include <memory>
#include <stdio.h>
using namespace std;
/* 
现代c++ 语法, 定义变量初始化
*/
struct data{
    int a,b,c;
};

void test_unique_fun()
{
    // data *p = make_unique<data>(); //-->编译错误,智能指针使用auto
    auto p = make_unique<data>();
    p->a=1;
    p->b=2;
    p->c=3;
}

void no_free_delete()
{
    data* p = new(data);
    p->a=1;
    p->b=2;
    p->c=3;
}

int main(void)
{
    test_unique_fun();
    no_free_delete();

    getchar();

    return 0;
}

/* 运行结果: 提示内存泄漏
 valgrind --leak-check=full ./1_make_unique指针指针.out

==31825== HEAP SUMMARY:
==31825==     in use at exit: 12 bytes in 1 blocks
==31825==   total heap usage: 4 allocs, 3 frees, 73,752 bytes allocated
==31825== 
==31825== 12 bytes in 1 blocks are definitely lost in loss record 1 of 1
==31825==    at 0x483BE63: operator new(unsigned long) (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==31825==    by 0x401271: no_free_delete() (1_make_unique指针指针.cc:23)
==31825==    by 0x4012B8: main (1_make_unique指针指针.cc:32)
 */