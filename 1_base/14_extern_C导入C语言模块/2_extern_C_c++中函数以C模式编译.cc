extern "C"{
int add(int a, int b)
{
    return a+b;
}
}

int main(void)
{
    int c = add(1,2);

    return 0;
}

/*
nm -C -g 2_extern_C_c++中函数以C模式编译.o
0000000000000000 T add       --> C语言API模式
0000000000000020 T main
 */