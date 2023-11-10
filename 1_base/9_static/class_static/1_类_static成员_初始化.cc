#include <iostream>
using namespace std;

class example {
private:
    static int a;
public:
    example(int num)
    {
        a = num;
    }
};

// int example::a;
int example::a=10;

int main ()
{
    example test(5);
 
   return 0;
}