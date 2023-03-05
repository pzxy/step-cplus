cmake_minimum_required(VERSION 3.0)

project(demo3)

aux_source_directory(. dir_srcs)
# 添加 math 子目录 指明本项目包含一个子目录 math，这样 math 目录下的 CMakeLists.txt 文件和源代码也会被处理 
add_subdirectory(math)

# 指定生成目标
add_executable(demo main.cc)

# 添加链接库 指明可执行文件 main 需要连接一个名为 MathFunctions 的链接库 
target_link_libraries(demo MathFunctions)
