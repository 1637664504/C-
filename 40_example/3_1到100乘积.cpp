#include <iostream>
using namespace std;

int main(void)
{
    register int sum=0;
    register int i;
    for(i=1;i<1000;i++)
        sum*=i;

    cout << "sum = " << sum << endl;
    return 0;
}