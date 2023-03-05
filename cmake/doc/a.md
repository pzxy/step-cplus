```cmake
# 用不了这么多
add_custom_target(Name [ALL] [command1 [args1...]]
                  [COMMAND command2 [args2...] ...]
                  [DEPENDS depend depend depend ... ]
                  [BYPRODUCTS [files...]]
                  [WORKING_DIRECTORY dir]
                  [COMMENT comment]
                  [JOB_POOL job_pool]
                  [VERBATIM] [USES_TERMINAL]
                  [COMMAND_EXPAND_LISTS]
                  [SOURCES src1 [src2...]])
# ALL：表明该目标会被添加到默认的构建目标，使得它每次都被运行；
# COMMAND：指定要在构建时执行的命令行；
# DEPENDS：指定命令所依赖的文件；
# COMMENT：在构建时执行命令之前显示给定消息；
# WORKING_DIRECTORY：使用给定的当前工作目录执行命令。如果它是相对路径，它将相对于对应于当前源目录的构建树目录；
# BYPRODUCTS：指定命令预期产生的文件。


add_custom_target(CopyTask ALL
    COMMAND echo "this is a command"
    WORKING_DIRECTORY /tmp
    COMMAND cp -f  . /tmp
  )
# COMMAND 只能执行这里的命令 https://cmake.org/cmake/help/latest/manual/cmake.1.html#run-a-command-line-tool

# 不链接，指定依赖顺序，先生成main的依赖(a.so,b.so),然后再去生成main.。
ADD_DEPENDENCIES(main a.so b.so)

SET_TARGET_PROPERTIES (target1 target2 ...PROPERTIES prop1 value1 prop2 value2 ...)
# 按照一般的习惯，静态库名字跟动态库名字应该是一致的，只是扩展名不同；
# 即：静态库名为 libhello.a； 动态库名为libhello.so ；
# 所以，希望 "hello_static" 在输出时，不是"hello_static"，而是以"hello"的名字显示，故设置如下：
SET_TARGET_PROPERTIES (hello_static PROPERTIES OUTPUT_NAME "hello")
GET_TARGET_PROPERTY (OUTPUT_VALUE hello_static OUTPUT_NAME)

- `RUNTIME_OUTPUT_DIRECTORY`：指定可执行文件的输出路径
- `LIBRARY_OUTPUT_DIRECTORY`：指定库文件的输出路径
- `ARCHIVE_OUTPUT_DIRECTORY`：指定静态库文件的输出路径
- `COMPILE_FLAGS`：指定编译选项
- `LINK_FLAGS`：指定链接选项
- `INCLUDE_DIRECTORIES`：指定头文件搜索路径
- `LINK_DIRECTORIES`：指定库文件搜索路径
- `OUTPUT_NAME`：指定输出文件的名称
- `DEBUG_POSTFIX`：指定调试版本输出文件的后缀名
- `RELEASE_POSTFIX`：指定发布版本输出文件的后缀名
```