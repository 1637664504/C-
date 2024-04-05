#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int add(int a, int b, int c)
{
    return a + b + c;
}

int main(void)
{
    add(3, 2);
    add(1, 2, 3);
    return 0;
}

/*
nm 2.o
0000000000000000 T _Z3addii
0000000000000018 T _Z3addiii

nm -C 2.o
0000000000000000 T add(int, int)
0000000000000018 T add(int, int, int)

 */