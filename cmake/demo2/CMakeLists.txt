cmake_minimum_required(VERSION 3.0)
project(demo2)
# add_executable(main.cc MathFunctions.cc)

# 查找当前目录下的所有源文件，并将名称保存到 dir_srcs 中。 auxiliary
aux_source_directory(. dir_srcs)
# 生成的目标
add_executable(demo ${dir_srcs})
