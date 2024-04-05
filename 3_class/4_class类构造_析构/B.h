
#pragma once

class A
{
private:
    int a;
    int b;
    class B *super;
public:
    A(int x, int y, class B *super_);
    void show_all(void);
};

class B
{
private:
    int c;
public:
    A *a;

    B(int x, int y, int z);
    void show_B(void);
};
