#include <stdio.h>
#include "demo_impl_b.h"
void demo_impl_b::impl_opt(void)
{
    printf("demo_impl_b ++ opt\n");
}
demo_impl_b::~demo_impl_b()
{
    printf("demo_impl_b ++ delete\n");
}

