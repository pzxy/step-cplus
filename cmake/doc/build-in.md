# 变量
```cmake
# 创建变量 SOURCES
set(SOURCES
    src/Hello.cpp
    src/main.cpp
)#创建一个变量，名字叫SOURCE。它包含了所有的cpp文件。

# 内建，总结CMAKE开头的根CMAKE命令走，progect跟项目走。
PROJECT_NAME      项目名 project (hello_cmake) 
CMAKE_PROJECT_NAME 由project（）命令设置的第一个项目的名称，即顶层项目。
CMAKE_SOURCE_DIR	根源代码目录，工程顶层目录。暂认为就是PROJECT_SOURCE_DIR
CMAKE_CURRENT_SOURCE_DIR	当前处理的 CMakeLists.txt 所在的路径
PROJECT_SOURCE_DIR	工程顶层目录
CMAKE_BINARY_DIR	运行cmake的目录。外部构建时就是build目录
CMAKE_CURRENT_BINARY_DIR	The build directory you are currently in.当前所在build目录
PROJECT_BINARY_DIR	暂认为就是CMAKE_BINARY_DIR
```
