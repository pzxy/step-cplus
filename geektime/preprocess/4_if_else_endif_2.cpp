// c++中还有其他预定义宏，比如“__cpp_decltype” “__cpp_decltype_auto” “__cpp_lib_make_unique”。
// 一般这种宏，在C++中没有定义，但是在编译中定义了，我们可以直接使用。
// 这个命令可以显示出来编译器定义的宏
// g++ -E -dM - < /dev/null
// 下面是命令显示的内容：
// #define __GNUC__ 5
// #define __unix__ 1
// #define __x86_64__ 1
// #define __UINT64_MAX__ 0xffffffffffffffffUL

// 使用编译器定义的宏，gcc 4_if_else_endif_2.cpp -E > test.p                       
#if defined(__cpp_decltype_auto)        //检查是否支持decltype(auto)
    cout << "decltype(auto) enable" << endl;
#else
    cout << "decltype(auto) disable" << endl;
#endif  //__cpp_decltype_auto

#if __GNUC__ <= 4
    cout << "gcc is too old" << endl;
#else   // __GNUC__ > 4
    cout << "gcc is good enough" << endl;
#endif  // __GNUC__ <= 4

#if defined(__SSE4_2__) && defined(__x86_64)
    cout << "we can do more optimization" << endl;
#endif  // defined(__SSE4_2__) && defined(__x86_64)


// 除了内置宏，还有自定义宏，引入不同的头文件。gcc 4_if_else_endif_2.cpp -E > test.p 

#if (NGX_FREEBSD)
#  include <ngx_freebsd.h>

#elif (NGX_LINUX)
#  include <ngx_linux.h>

#elif (NGX_SOLARIS)
#  include <ngx_solaris.h>

#elif (NGX_DARWIN)
#  include <ngx_darwin.h>
#endif

// 使用 0，1 来开启关闭条件

#if 0          // 0即禁用下面的代码，1则是启用
  cout << "0" << endl;         // 任意的代码
#endif         // 预处理结束

#if 1          // 1启用代码，用来强调下面代码的必要性
  cout << "1" << endl;           // 任意的代码
#endif         // 预处理结束

