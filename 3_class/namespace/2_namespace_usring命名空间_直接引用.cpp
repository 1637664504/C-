#include <iostream>
using namespace std;

namespace my_namespace{
    int myNamespace_x;
    int myNamespace_y;
    void myNamespace_fun()
    {
        cout << "111" << endl;
    }

}
using namespace my_namespace;

int main(void)
{
    myNamespace_x =1;
    myNamespace_fun();
    my_namespace::myNamespace_y = 2;
    return 0;
}