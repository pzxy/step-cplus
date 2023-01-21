// define 宏定义，也就是文本替换，使用时以简化代码，逻辑清晰为目标。
// 因为宏的展开、替换发生在预处理阶段，不涉及函数调用、参数传递、指针寻址，没有任何运行期的效率损失，所以对于一些调用频繁的小代码片段来说，用宏来封装的效果比 inline 关键字要更好，因为它真的是源码级别的无条件内联。
// 宏是没有作用域概念的，全局生效。一些起临时作用的宏，最好是用完后尽快用“#undef”取消定义。
#define CUBE(a) (a) * (a) * (a)  // 定义一个简单的求立方的宏
cout << CUBE(10) << endl;        // 使用宏简化代码
cout << CUBE(15) << endl;        // 使用宏简化代码
#undef CUBE                      // 使用完毕后立即取消定义

// 定义常量，枚举
#define MAX_BUF_LEN    65535
#define VERSION        "1.0.18"
// 定义命名空间
#define BEGIN_NAMESPACE(x)  namespace x {
#define END_NAMESPACE(x)    }

// 使用命名空间
BEGIN_NAMESPACE(my_own)

// functions and classes

END_NAMESPACE(my_own)

// 执行 gcc 3_define_undef.cpp -E > test.p 可以看到namespace 