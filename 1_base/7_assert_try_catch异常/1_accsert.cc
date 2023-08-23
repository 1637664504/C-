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