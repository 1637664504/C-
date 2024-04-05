#include <iostream>
#include <assert.h>
using namespace std;

int main(void)
{
    void *p = NULL;
    assert(p == NULL);
    assert(p);          // 报错
    cout << "hello, world. c++" << endl;

    return 0;
}

/* 运行结果
1_accsert.out: 1_accsert.cc:9: int main(): Assertion `p' failed.
Aborted
 */