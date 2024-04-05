
#ifndef __demo_impl__h
#define __demo_impl__h
class demo_impl{
public:
    // 纯虚函数
    virtual void impl_opt(void){};
    virtual ~demo_impl(){};
    virtual int impl_get() = 0;
};
#endif