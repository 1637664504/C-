/* 
sudo apt update
sudo apt install libgoogle-glog-dev
 */

#include <iostream>
#include <gflags/gflags.h>

DEFINE_string(message, "Hello, World!", "A message to print");
DEFINE_int32(vari32, 11, "测试int32");
DEFINE_uint32(varu32, 12, "测试uint32");
DEFINE_double(varfloat, 13.0, "测试float");
DEFINE_bool(varbool, false, "测试bool");

int main(int argc, char** argv) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    std::cout << FLAGS_message<< std::endl;
    std::cout << FLAGS_vari32<< std::endl;
    std::cout << FLAGS_varu32<< std::endl;
    std::cout << FLAGS_varfloat<< std::endl;
    std::cout << FLAGS_varbool<< std::endl;
    return 0;
}


// 测试1
/* ./1_gflags_命令行参数.out
Hello, World!
11
12
13
0

 */


// 测试2
/*  ./1_gflags_命令行参数.out --message="abc" --vari32=21 --varu32=22 \
--varfloat=23.0 --varbool=true

Hello, World!
abc
21
22
23
1

 */