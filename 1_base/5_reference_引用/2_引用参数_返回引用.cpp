#include <iostream>
#include <stdint.h>
using namespace std;
 
const string& get_big_string(const string& s1, const string& s2)
{
    return s1.size() > s2.size() ? s1 : s2;
}


int& get_num(int& a, int& b)
{
    return a > b ? a : b;
}


class A {
private:
    int a;
public:
    A(int num) :a(num)
    {
        
    }

    int get_num()
    {
        return a;
    }
};

A& get_class_A(A& a1, A& a2)
{
    return a1.get_num() > a2.get_num() ? a1 : a2;
}

int main()
{
    string s1 = "hello world";
    string s2 = "I am supper man";
    const string& s3 = get_big_string(s1, s2);
    cout << s3 << endl;

    int a = 2;
    int b = 5;
    int& c = get_num(a, b);
    cout << c << endl;

    A a1(3);
    A a2(5);
    A& a3 = get_class_A(a1, a2);
    cout << a3.get_num() << endl;

    return 0;
}
 
/*
I am supper man
5

*/
