env = Environment()
env['CCFLAGS'] = '-g'
env['CXXFLAGS'] = '-g'
# env.Append(CXXFLAGS=['-Ddebug'])
src_files=Split('demo_impl_a.cpp demo_impl_b.cpp demo_impl_server.cpp')
env.Program('a.out', src_files)
