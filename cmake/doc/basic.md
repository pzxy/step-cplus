```cmake
# 详细输出
make VERBOSE = 1
# 查看指定函数的作用
cmake --help-command SET_TARGET_PROPERTIES
# 库的源文件Hello.cpp生成静态库hello_library
# add_library（）函数用于从某些源文件创建一个库，默认生成在构建文件夹
# 在add_library调用中包含了源文件，用于创建名称为libhello_library.a的静态库。

add_library(hello_library STATIC 
    src/Hello.cpp
)
# 为 lib或者可执行文件 添加头文件
target_include_directories(hello_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

#链接可执行文件和静态库
add_executable(hello_binary 
    src/main.cpp
)
# 链接库 对于hello_binary，它不是库，所以不会被链接。直接private自己用这个库就行
target_link_libraries(hello_binary
    PRIVATE 
        hello_library
)
# PUBLIC INTEFRACE PRIVATE
PUBLIC 目标库a用，别的库b链接了a，那么b也能用
INTERFACE 目标库a不用，别的库b链接了a，b可以用
PRIVATE 目标库a用


#根据Hello.cpp生成动态库
add_library(hello_library SHARED 
    src/Hello.cpp
)
#给动态库hello_library起一个别的名字hello::library
add_library(hello::library ALIAS hello_library)
#为这个库目标，添加头文件路径，PUBLIC表示包含了这个库的目标也会包含这个路径
target_include_directories(hello_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)
#链接库和可执行文件，使用的是这个库的别名。PRIVATE 表示
target_link_libraries( hello_binary
    PRIVATE 
        hello::library
)

# Add the "make analysis" target

if( CPPCHECK_FOUND )
    add_custom_target(analysis)
    ADD_DEPENDENCIES(analysis ${ALL_ANALYSIS_TARGETS})
    set_target_properties(analysis PROPERTIES EXCLUDE_FROM_ALL TRUE)
    message("analysis analysis targets are ${ALL_ANALYSIS_TARGETS}")
endif()
```