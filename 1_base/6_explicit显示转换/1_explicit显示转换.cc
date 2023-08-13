class A
{
private:
    int r;
public:
    A(int radius){
        r = radius;
    }
};

class B
{
private:
    int r;
public:
    explicit B(int radius){
        r = radius;
    }
};

int main()
{
    A a1 = A(3);
    A a2 = 3;

    B b1 = B(2);
    B b2 = 2;   // 报错,只运行显示转换

	return 0;
}

/* 
g++ -o 1_explicit显示转换.o -c -ggdb3 -O0 1_explicit显示转换.cc
1_explicit显示转换.cc: In function 'int main()':
1_explicit显示转换.cc:27:12: error: conversion from 'int' to non-scalar type 'B' requested
   27 |     B b2 = 2;
      |            ^

 */