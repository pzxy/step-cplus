cmake_minimum_required(VERSION 3.0)
project(demo4)

# 加入一个配置文件，用于处理CMake 对源码的配置,
# 将config.h.in中的内容 替换成 config.in 中的内容
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

# 是否使用自己的 MathFunctions 库
option (USE_MYMATH "Use provided math implementation" ON)
option (DEMO "this a demo" ON)

# 是否加入 MathFunctions 库
if (USE_MYMATH)
include_directories("${PROJECT_SOURCE_DIR}/math")
add_subdirectory(math)
set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)

endif(USE_MYMATH)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量

aux_source_directory(. dir_srcs)
add_executable(demo ${dir_srcs})
target_link_libraries(demo ${EXTRA_LIBS})

# 执行 ccmake .
# USE_MYMATH -> ON , c g 
# make