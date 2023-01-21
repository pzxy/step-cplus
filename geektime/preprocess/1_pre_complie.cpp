#                              // 预处理空行
#if __linux__                  // 预处理检查宏是否存在
#   define HAS_LINUX    1      // 宏定义，有缩进
#endif                         // 预处理条件语句结束
#                              // 预处理空行
// g++ 1_pre_complie.cpp -E -o a.cxx 
// 不过可以让 GCC 使用“-E”选项，略过后面的编译链接，只输出预处理后的源码