#include <iostream>
using namespace std;
// auto是编译器推导类型的。
void demo1()
{
    cout << "> demo1" << endl;
    int n = 5;
    // 从左往右推导，auto *pn = &n推导出 auto位int，但是 m = 10.0推导出auto为double，类型不一致。
    // auto *pn = &n, m = 10.0;
    auto *pn = &n, m = 10;

    // 条件表达式时，类型范围以大的为准,这里返回5，但是类型是double
    auto i = true ? 5 : 8.0;
}

struct sometype
{
    // 错误的
    // auto k = 5;
    static const auto i = 5;  // c++11
    static inline auto j = 5; // c++17
};

// 什么时候使用auto？
// - 迭代器
// - lambda表达式

// 返回类型推导
auto demo2(int a1, int a2)
{
    cout << "> demo2" << endl;
    return a1 + a2;
} // c++14

// 非类型模版：参数是确定的值。是表达式，而不是具体类型，并且不能是运行时计算的。
template <auto N>
void demo3()
{
    cout << "> demo3" << endl;
    std::cout << N << std::endl;
}
// 推导规则
// 如果auto声明的变量是按值初始化，则推导出的类型会忽略cv限定符。
// 进一步解释为，在使用auto声明变量时，既没有使用引用，也没有使用指针，
// 那么编译器在推导的时候会忽略const和volatile限定符。当然auto本身也支持添加cv限定符：
// 也就是说如果是auto i这种的话，那么就是值类型。
void demo4()
{
    cout << "> demo4" << endl;
    const int i = 5;
    auto j = i;  // auto推导类型为int，而非const int
    auto &m = i; // auto推导类型为const int，m推导类型为const int&
    // auto *k = i;      // auto推导类型为const int，k推导类型为const int*
    const auto n = j; // auto推导类型为int，n的类型为const int
}

int main()
{
    demo1();
    demo2(1, 2);
    demo3<5>(); // 5.0 不行，double不能作为模版非类型参数。
    demo4();
}