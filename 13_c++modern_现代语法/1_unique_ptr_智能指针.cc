#include <iostream>
#include <memory>
using namespace std;

class widget
{
private:
    std::unique_ptr<int[]> data;

public:
    widget(const int size)
    {
        data = std::make_unique<int[]>(size); //等价于 new int[size];
    }
    void do_something()
    {
        cout << "do something" << endl;
    }
};

void functionUsingWidget()
{
    widget w(10); // lifetime automatically tied to enclosing scope
                  // constructs w, including the w.data gadget member
    // ...
    w.do_something();
    // ...
} // automatic destruction and deallocation for w and w.data

int main(void)
{
    functionUsingWidget();

    return 0;
}