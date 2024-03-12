## 1.个人c++代码测试.验证.小功能开发

编辑器 vscode

调试器 gdb

编译器 g++ / clang

系统 ubuntu/debian

构建工具 scons (python语法的make/cmake构建)

github 无法使用ssh推送代码，迁移到gitee:
git@gitee.com:zero2200/3_cpp-practice.git

# 1.C++基本语法
## 1.string字符串
- [string_拼接格式化: buf1+buf2](2_string/1_string_拼接格式化.cpp)
- [函数返回string: return string](2_string/3_string_函数返回string值.cpp)
- [sstream 格式化拼接 snprintf](2_string/3_sstream/1_stringstream_字符串拼接_格式化_snprintf.cc)
- [sstream 格式化拆分 sscanf](2_string/3_sstream/2_stringstream_字符串_格式化拆分_sscanf.cc)

数字转换
- [inr float转string](2_string/5_int_float转string.cc)

## 2.reference引用
- [引用参数](1_base/5_reference_引用/1_引用作为参数.cpp)
- [引用参数-->返回引用结果](1_base/5_reference_引用/2_引用参数_返回引用.cpp)
- [string字符串引用](1_base/5_reference_引用/6_string_函数引用_修改字符串.cpp)
- [类的引用成员 初始化: class.&a 初始化](1_base/5_reference_引用/3_类-引用成员初始化.cc)
- [指针转引用 方法 --> 仅函数引用参数有效](1_base/5_reference_引用/4_指针转引用.cc)
- [char\[\] 数组转引用](1_base/5_reference_引用/5_char_做引用.cc) -->编译失败


## 3.class类
构造
- [类的-成员 初始化](3_class/4_class类构造_析构/2_类的-类成员_初始化.cpp)
- [类的-引用成员 初始化](1_base/5_reference_引用/3_类-引用成员初始化.cc)

- [父类-引用子类]() --父类不能引用子类的函数,成员, 设计不合理,请重新设计
- [copy_constructor拷贝构造](3_class/5_拷贝构造copy_constructor/5_copy_constructor拷贝构造.cpp)
- [copy_constructor无拷贝构造 执行一次构造,二次析构](3_class/5_拷贝构造copy_constructor/6_copy_constructor_无拷贝构造_1次构造_2次析构_异常现象.cpp)


虚函数
- [1.无虚函数重写 +gdb查看内存](3_class/8_virtual虚函数/1_无虚函数-重写.cpp)
- [2.虚函数重写 +gdb查看内存](3_class/8_virtual虚函数/1.1_有虚函数_重写.cpp)
- [sizeof class 类 占用空间大小](3_class/6_sizeof_class类大小/1_class_sizeof.cpp)
- [sizeof class 虚函数 占用空间大小](3_class/6_sizeof_class类大小/2_sizeof_虚函数-对齐-静态数据大小.cpp)
- [sizeof class 类多个虚函数 占用空间大小](3_class/6_sizeof_class类大小/3_sizeof_类包含多个虚函数.cpp)

static
- [类-static成员 初始化](1_base/9_static/class_static/1_类_static成员_初始化.cc)
- [类-static指针成员 初始化](1_base/9_static/class_static/2_类_static_指针成员_初始化.cc)

多态
- [多态函数表查看](3_class/7_多态/1_多态查看.cpp)


## 5.vector/list/map 数据结构
### 1.vector 动态矢量数组
- [vector实例](4_container/vector)
- vector 通过数组初始化 [vector_array_数组相互转换.cc](4_container/vector/10_vector_array_数组相互转换.cc)

### 2.list列表
- [list 实例](4_container/list)

### 3.map 映射/字典
- [map 实例](4_container/map)
- [map c++20现代化遍历](4_container/map/12_map_函数指针_现代化初始化.cc)
- [map <string, 函数指针>](4_container/map/11_map_函数指针.cc)
- [类构造函数中, 初始化map](4_container/map/13_map_类里面初始化.cc)


### queue队列
- [queue队列](4_container/4_queue队列/1_queue队列.cpp)

### deque双端队列
- [deque 双端队列](4_container/5_deque双端队列/1_deque_双端队列.cpp)
- [deque 双端队列 增删改查](4_container/5_deque双端队列/2_deque增删改查.cpp)

## 6.语法
- [explicit 显示转换](1_base/6_explicit显示转换/1_explicit显示转换.cc)
- [decltype 自动类型推导](1_base/7_auto_decltype自动类型推导/1_decltype_自动推导数据类型.cpp)
- [decltype class自动类型推导](1_base/7_auto_decltype自动类型推导/2_decltype_推导类.cpp)

### static
- [类_static成员_初始化](1_base/9_static/class_static/1_类_static成员_初始化.cc)
- [类_static指针成员_初始化](1_base/9_static/class_static/2_类_static_指针成员_初始化.cc)


### namespace命名空间
- [namespace_命名空间引用](1_base/13_namespace/1_namespace_命名空间引用.cpp)
- [usring namespace 命名空间_直接引用](1_base/13_namespace/2_namespace_usring命名空间_直接引用.cpp)
- [namespace 命名空间 实例](1_base/13_namespace/3_多文件namespace实例)

### unique智能指针
- [智能指针](7_关键字/1_unique智能指针/1_make_unique指针指针.cc)

## 7.int float double基本数据类型
- [int 2进制 8进制 16进制表达方式](1_base/8_int_float_double基本数据类型/1_int_2进制_8进制_16进制表达.cc)
- [sizeof char, int, long ,long long, float, double占用内存大小](1_base/12_sizeof_对象占用内存空间大小/1_limit_number_size.cpp)


## 11.try_catch accsert 异常
- [accsert 断言](1_base/7_assert_try_catch异常/1_accsert.cc)
- [uint8_t unsigned char 计算溢出](1_base/3_整数溢出/1_1字节溢出.cpp)


## 12.templat模板
- [template 模板: add](5_template/1_template_add实现.cpp)
- [template 模板: swap交换](5_template/2_template_swap实现.cpp)

# 2.默认库
## thread线程库
- [线程参数_值_地址_引用](1_base/11_多线程/3_线程传递_地址_引用参数.cc)
- [线程函数_为类的成员函数](1_base/11_多线程/5_thread_线程_类的成员函数.cc)

## chrono 时间
- [chrono_获取当前时间戳](6_c++库/2_chrono_时间/1_chrono_获取当前时间戳.cc)

# 3.开源库
- [spdlog日志](32_第3方库/01_spdlog日志库)
- [mqtt 话题订阅发布](32_第3方库/12_mqtt)
- [蓝牙bluetooth](25_外设模块/8_蓝牙bluetooth)
