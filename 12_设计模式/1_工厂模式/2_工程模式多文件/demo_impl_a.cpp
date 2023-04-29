#include <stdio.h>
#include "demo_impl_a.h"
void demo_impl_a::impl_opt(void)
{
    printf("demo_impl_a -- opt\n");
}

demo_impl_a::~demo_impl_a(void)
{
    printf("demo_impl_a -- delete\n");
}
