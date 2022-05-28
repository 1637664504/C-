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

int main(void)
{
    namespace my = my_namespace;
    my::myNamespace_x = 1;
    my::myNamespace_fun();
    my_namespace::myNamespace_y = 2;
    return 0;
}