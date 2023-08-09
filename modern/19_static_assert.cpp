#include <iostream>
#include <type_traits>

using namespace std;

// 1. 运行时断言
// 只能debug使用，release版本中不起作用。言（头文件cassert已经通过宏NDEBUG对Debug和Release版本做了区分处理，我们可以直接使用assert）。

// 2. 模拟静态断言。用到的时候再看书。
// 3. 静态断言c++11，
// - 所有处理必须在编译期间执行，不允许有空间或时间上的运行
// 时成本。
// - 它必须具有简单的语法。
// - 断言失败可以显示丰富的错误诊断信息。
// - 它可以在命名空间、类或代码块内使用。
// - 失败的断言会在编译阶段报错。
// 4. 单参数静态断言，C++17肯定支持，C+++17之前有的编译器可能支持。

class A
{
};
class B : public A
{
};
class C
{
};
template <class T>
class E
{
    static_assert(std::is_base_of<A, T>::value);
};
int main(int argc, char *argv[])
{
    E<C> x; // 使用正确，但由于A不是C的基类，会触发失败断言
    static_assert(sizeof(int) < 4); // 使用正确，但表达式返回false，会触发失败断言
}
