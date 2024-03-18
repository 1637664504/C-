// rvalue-references-move-semantics.cpp
// 利用移动语义，可以编写将资源（如动态分配的内存）从一个对象转移到另一个对象的代码
// 提高应用程序的性能

#include "MemoryBlock.h"
#include <vector>
using namespace std;

int main()
{
    // Create a vector object and add a few elements to it.
    vector<MemoryBlock> v;
    v.push_back(MemoryBlock(25));
    v.push_back(MemoryBlock(75));

    // Insert a new element into the second position of the vector.
    v.insert(v.begin() + 1, MemoryBlock(50));

    return 0;
}