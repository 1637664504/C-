
#include <iostream>
#include "demo_impl.h"
#include "demo_impl_a.h"
#include "demo_impl_b.h"

enum E_Class_Type{
    Class_A = 0,
    Class_B = 1,
};

class demo_server{
public:
    demo_impl *impl = NULL;

    void init_impl(E_Class_Type type)
    {
        demo_impl *impl;
        if(type == Class_A){
            impl = new demo_impl_a();
        }
        else if(type == Class_B){
            impl = new demo_impl_b();
        }

        this->impl = impl;
        this->type = type;
    }
    ~demo_server()
    {
        if(impl != NULL){
            delete this->impl;
            this->impl = NULL;
        }
    }
private:
    E_Class_Type type;
};

int main(int argc, char **argv)
{
    E_Class_Type type = Class_A;
    demo_server ser;
    ser.init_impl(type);
    ser.impl->impl_opt();

    return 0;
}