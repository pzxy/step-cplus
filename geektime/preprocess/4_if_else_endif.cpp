// 这是条件编译
// __cplusplus 预定义宏，它标记了 C++ 语言的版本。

#ifdef __cplusplus                      // 定义了这个宏就是在用C++编译
    extern "C" {                        // 函数按照C的方式去处理
#endif
    void a_c_function(int a);
#ifdef __cplusplus                      // 检查是否是C++编译
    }                                   // extern "C" 结束
#endif

#if __cplusplus >= 201402                // 检查C++标准的版本号
    cout << "c++14 or later" << endl;    // 201402就是C++14
#elif __cplusplus >= 201103              // 检查C++标准的版本号
  //  cout << "c++11 or before" << endl;   // 201103是C++11
#else   // __cplusplus < 201103          // 199711是C++98
//  error "c++ is too old"               // 太低则预处理报错
#endif  // __cplusplus >= 201402         // 预处理语句结束

