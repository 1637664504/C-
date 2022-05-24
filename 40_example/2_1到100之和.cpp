#include <iostream>
using namespace std;

int main(void)
{
    int sum=0;
    int i;
    for(i=0;i<100;i++)
        sum+=i;

    cout << "sum = " << sum << endl;
    return 0;
}