## 模板1
import os

env = None
# 1.编译器
if os.system("which clang"):
    env = Environment()
else:
    # clang编译器
    env = Environment(tools=["default", "clang"])
    env["CC"] = ["clang"]
    env["CXX"] = ["clang++"]

env["PROGSUFFIX"] = ".out"            # 可执行后缀.out
env["CCFLAGS"] = " -ggdb3 -O0 -Wall"  # gdb 调试开关
src_list = [
    "demo.cc",
]
for src in src_list:
    env.Program(Split(src))


## 模板2
env = Environment()
env["PROGSUFFIX"] = ".out"            # 可执行后缀.out
env["CCFLAGS"] = " -ggdb3 -O0 -Wall"  # gdb 调试开关
env.Program("demo.c")