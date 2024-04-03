class Base
{
public:
    virtual int foo() { return 0; }
};
class Derived : public Base
{
public:
    int foo() { return 1; }
};

int main(void)
{
    Base *base_ptr = new Derived();
    Derived *derived_ptr = dynamic_cast<Derived *>(base_ptr);
    if (derived_ptr) // 有效性检查
    {
        derived_ptr->foo();
    }

    return 0;
}