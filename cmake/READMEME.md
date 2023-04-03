# 项目的结构组织
项目的结构组织,主要通过 `add_subdirectory()` 来添加一些目录.
# 如何找目录
找目录有两个,一个是在源码中找,也就是通过头文件导入,另外就是在链接的时候,指定链接文件的存在目录.

如何在源码中找呢?
```cmake
# 等于说在源文件中,我就可以访问到 src/xtopcom 中的文件或者目录.
# 比如有 src/xtopcom/a/a.h
# 我就可以通过 #include "a/a.h" 引入这个文件.
include_directories(src/xtopcom)
# SYSTEM的含义就是可以信任代码没有问题,并且引入的时候
# 可以这样 #include <a/a.h> 
include_directories(SYSTEM src/xtopcom)
```
link_directories 是链接的搜索路径,不是编译的时候.应该可以有多个链接的目录,这样在这里找不到就去下个地方找了.

如何在链接库中找到?
link_libraries 指定要链接的lib,一般是静态文件. 也能使用 target_link_libraries来链接,链接的时候可以指定顺序.
```cmake
add_dependencies(xvm xstatestore xconfig xstore xchain_upgrade xcertauth xdata xdata xevm_common xcommon xrouter xcodec xbasic xxbase)
# 可选INTERFACE PRIVATE PUBLIC等,如果相互依赖,就选择INTERFACE
target_link_libraries(xvm PRIVATE xstatestore xconfig xevm_common xrouter xcertauth xdata xchain_upgrade xdata xcommon xcodec xbasic xstore xxbase protobuf jsoncpp ethash keccak)
```
这里面的add_dependencies是指定这几个依赖的编译顺序.

# 如何传参数
传参数也分两种,一种是cmake参数,另外一种是c++的编译参数

cmake参数:
其实就是变量,可以set,也可以option都行.
```cmake
set(AAA ON)
# option再执行ccmake的时候可以显示aaa注释.
option(AAA "aaa" OFF)
```
执行cmake命令或者ccmake的时候,可以通过-DAAA将AAA传入,也可以传入的同时给AAA设置一个新的值.

add_definitions可以给编译器添加预定义宏,可以在代码中实用这个宏.
```cmake
add_definitions(-DMSGPACK_NO_BOOST)
```
在代码中,可可以获取这个宏进行判断
```cpp
#ifdef MSGPACK_NO_BOOST
....业务代码
#endif
```

c++的编译参数:
通过add_compile_options传入
```txt
add_compile_options(-static-pie)
# 这是$<...>语法,含义如果TARGET_PROPERTY的属性等于LINKER_LANGUAGE,就在CXX后面增加-fexceptions
add_compile_options($<$<STREQUAL:$<TARGET_PROPERTY:LINKER_LANGUAGE>,CXX>:-fexceptions>)
```