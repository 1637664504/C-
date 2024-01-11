import os

env = None
# 1.编译器
if os.system("which clang"):
    env = Environment()
else:
    # clang编译器
    env = Environment(tools = ['default', 'clang'])
    env['CC']=['clang']
    env['CXX']=['clang++']

# 2.自动生成后缀.out
def build_out(src_file):
    src = Split(src_file)
    target = os.path.splitext(src[0])[0]+'.out'
    env.Program(target, src)

env['CCFLAGS'] = ' -ggdb3 -O0'         # gdb 调试开关
# env['CCFLAGS'] += ' -DDEBUG'          # Debug log开关

build_out("demo.cc")