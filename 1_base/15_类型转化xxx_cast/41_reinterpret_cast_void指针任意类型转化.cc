#include <iostream>
using namespace std;

int main(void)
{
    int* int_ptr = new int(5);
    char* char_ptr = reinterpret_cast<char*>(int_ptr);

    void *void_ptr = new int(5);
    int* int_ptr2 = reinterpret_cast<int*>(void_ptr);

    return 0;
}