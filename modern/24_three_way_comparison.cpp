#include <iostream>
// #include <compare>
using namespace std;
// c++20 开始
// g++ -std=c++20 24_three_way_comparison.cpp && ./a.out
// 1. 太空飞船 spaceship 运算符。
void demo1()
{
    // 7 和 11比较，返回结果，只能和自身或者0比较。
    // 这里7小于11，所以等于-1，-1小于0，所以这里b为1
    bool b = 7 <=> 11 < 0;
    cout << ">> demo1" << endl;
    cout << "b: " << b << endl;
}

// 2. 三向比较的返回类型。
// 为std::strong_ordering、std::weak_ordering以及std:: partial_ordering

// 2.1 std::strong_ordering
// std::string_ordering有三种比较结果
// std::strong_ordering::less 表示 lhs<rhs
// std::strong_ordering::equal 表示 lhs=rhs
// std::strong_ordering::greater 表示 lhs>rhs
// std::strong_ordering表示在任何情况下lhs和rhs都可以互相替换。也就是fx(lhs)==fx(rhs)
// 比如基本类型 int
struct B
{
    int a;
    long b;
    // 自定义类型三向比较运算符函数，需要用户显式默认声明。
    auto operator<=>(const B &) const = default;
};
struct D : B
{
    short c;
    auto operator<=>(const D &) const = default;
};
void demo21()
{
    cout << ">> demo21" << endl;
    std::cout << typeid(decltype(7 <=> 11)).name() << endl;
    D x1, x2;
    // 这里这所以能比较，是因为显示声明了三向比较运算符，并且内部的基本类型也可以进行三向比较。
    std::cout << typeid(decltype(x1 <=> x2)).name() << endl;
}

// 2.2 std::weak_ordering 也有三种比较结果
// std::weak_ordering::less std::weak_ordering::equivlent 以及 std::weak_ordering::greater
// std::weak_ordering  即使 lhs == rhs 也不能直接替换，也就是说 fx(lhs) != fx(rhs)
// 这种情况只在自定义类型中才有。

// 2.3 std::partial_ordering，用到了在看

// 3. 对基本类型的支持，用到了再看

// 4. 自动生成比较运算符函数 std::rel_ops，用到了再看。

// 5. 兼容旧代码，实现了 < 和 == 运算符函数的数据类型，自动生成三向比较符函数代码。
int main()
{
    demo1();
    demo21();
}