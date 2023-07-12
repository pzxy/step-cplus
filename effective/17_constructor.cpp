#include <iostream>
#include <mutex>
using namespace std;
// https://en.cppreference.com/w/cpp/language/rule_of_three
// 1. 一个类如果什么都不写,所有构造都会生成（默认构造函数、拷贝赋值运算符、拷贝构造函数、移动构造函数）
class A
{
};
void demo1()
{
    cout << "> demo1" << endl;
    A a{};
    A b = a;
    A c{a};
    A d{std::move(a)};
};

// 2. 一个类如果写了构造函数（有参数或者无参数），则默认构造函数不会生成了。
class A2
{
public:
    A2(int x) {}
};
void demo2()
{
    cout << "> demo2" << endl;
    // A2 a{};
    // A2 b = a;
    // A2 c{a};
    // A2 d{std::move(a)};
};

// 3. 一个类中的基类不能拷贝、成员变量不能拷贝，则不会生成 拷贝构造函数、拷贝赋值运算符、移动构造函数。(不能拷贝：锁、变量本身就没有拷贝构造函数).
class A3
{
public:
    mutex m;
};
void demo3()
{
    cout << "> demo3" << endl;
    A3 a{};
    // A3 b = a;
    // A3 c{a};
    // A3 d{std::move(a)};
};
int main()
{
    demo1();
    demo2();
    demo3();
}

// 三个特殊函数：拷贝构造函数、移动构造函数和析构函数，如果需要其中一个，则需要定义全部三个。
// 五个关键字：delete、default、override、final 和 constexpr。
// 零指针：使用智能指针等现代C++特性来尽可能避免裸指针的使用。

// 总结：
// 1. 类会自己生成构造函数、拷贝赋值、拷贝构造、移动构造。
// 2. 如果写了带参数的构造，则都不会生成了。
// 3. 如果类的基本或者成员变量不能拷贝，也不会生成默认构造函数。
