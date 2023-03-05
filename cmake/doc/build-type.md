```cmake
# 构建类型
Release 不能debug，优化。 -O3 -DNDEBUG
Debug 调试版本。-g
MinSizeRel—— 最小体积版本。-Os -DNDEBUG
RelWithDebInfo—— 既优化又能调试。-O2 -g -DNDEBUG
# 使用，-DCMAKE_BUILD_TYPE=Release ,默认Debug
cmake .. -DCMAKE_BUILD_TYPE=Release

# set设置变量， unset取消。有三种
# 1. 正常变量 set(<variable> <value>... [PARENT_SCOPE])
set (val sub_hello) # val变量的值为sub_hello。只有当前目录中访问
set (val par_hello PARENT_SCOPE) # 父目录中可以访问。
# 2. CACHE变量 set(<variable> <value>... CACHE <type> <docstring> [FORCE])
set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
# CACHE，cmake时生成CMakeCache.txt，再次cmake使用CMakeCache.txt值。
# FORCE，cmake时覆盖CMakeCache.txt中相同值。
# STRING "Choose the type of build." ccmake时起作用。此外还有BOOL，FILEPATH，PATH，INTERNAL
# STRING 如果设置了缓存，下拉框
# BOOL ，ON/OFF
# FILEPATH，磁盘文件路径，对话框
# PATH，磁盘上目录，对话框
# INTERNAL，不显示内容，持久存储变量。
# 3. 环境变量  set(ENV{<variable>} [<value>])，$ENV{<varible>}获取。

# 设置一个 CMAKE_BUILD_TYPE 变量 ，表示缓存，值是一个STRINGS 字符串列表，就是这四个。
# 如果使用gui，可以更改变量的值从这四个里面。ccmake ..
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
"MinSizeRel" "RelWithDebInfo")
# 如果不使用gui选择值，可以这样选择。
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Add debug-specific build settings here
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    # Add release-specific build settings here
endif()

```

