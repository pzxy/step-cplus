```cmake
# 设置编译选项，哲理设置了 EX2的 编译选项。
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEX2" CACHE STRING "Set C++ Compiler Flags" FORCE)


add_executable(cmake_examples_compile_flags main.cpp)
# 为可执行文件添加私有编译定义 推荐
# 如果范围PUBLIC或INTERFACE，该定义-DEX3也将包含在链接此目标（cmake_examples_compile_flags）的所有可执行文件中。
target_compile_definitions(cmake_examples_compile_flags 
    PRIVATE EX3
)
# 直接使用
cmake .. -DCMAKE_CXX_FLAGS="-DEX3"


# 编译选项也可以这样设置
target_compile_options(<target> [BEFORE]
  <INTERFACE|PUBLIC|PRIVATE> [items1...]
  [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])


```