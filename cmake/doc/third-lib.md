```cmake
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (third_party_include)

# find_package（）函数将从CMAKE_MODULE_PATH中的文件夹列表中搜索“ FindXXX.
# cmake”中的CMake模块。 find_package参数的确切格式取决于要查找的模块。 
# 这通常记录在FindXXX.cmake文件的顶部。
# find a boost install with the libraries filesystem and system
# 使用库文件系统和系统查找boost install
# Boost-库名称。 这是用于查找模块文件FindBoost.cmake的一部分
# 1.46.1 - 需要的boost库最低版本
# REQUIRED - 告诉模块这是必需的，如果找不到会报错
# COMPONENTS - 要查找的库列表。从后面的参数代表的库里找boost
# 可以使用更多参数，也可以使用其他变量。 在后面的示例中提供了更复杂的设置。
find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)

#这是第三方库，而不是自己生成的静态动态库
# check if boost was found
# 大多数被包含的包将设置变量XXX_FOUND，该变量可用于检查软件包在系统上是否可用。
if(Boost_FOUND)
    message ("boost found")
    # 它会自动导出变量，这些变量可以通知用户在哪里可以找到库，头文件或可执行文件。 与XXX_FOUND变量类似，它们与包绑定在一起，通常记录在FindXXX.cmake文件的顶部
    # Boost_INCLUDE_DIRS - boost头文件的路径
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message (FATAL_ERROR "Cannot find Boost")
endif()

# Add an executable
add_executable(third_party_include main.cpp)

# link against the boost libraries
# 使用别名
target_link_libraries( third_party_include
    PRIVATE
        Boost::filesystem
)
# cmake3.5以后 boost支持别名，在这之前要用 
# link against the boost libraries
target_link_libraries( third_party_include
    PRIVATE
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
)
```


```cmake
# Add a custom CMake Modules directory
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules
                      ${CMAKE_MODULE_PATH})

# find the cppcheck binary
find_package(CppCheck)

# static analysis. Should be before adding subprojects
set (ALL_ANALYSIS_TARGETS)

# Add sub directories
add_subdirectory(subproject1)
add_subdirectory(subproject2)


# Add the "make analysis" target
if( CPPCHECK_FOUND )
    add_custom_target(analysis)
    ADD_DEPENDENCIES(analysis ${ALL_ANALYSIS_TARGETS})
    set_target_properties(analysis PROPERTIES EXCLUDE_FROM_ALL TRUE)
    message("analysis analysis targets are ${ALL_ANALYSIS_TARGETS}")
endif()
```