#include <iostream>
using namespace std;

// 1. 使用函数返回类型后置声明函数
// 返回函数指针方式1，别名
int bar_impl(int x)
{
    return x;
}
// typedef int (*bar)(int);
using bar = int (*)(int);
bar foo1()
{
    return bar_impl;
}
// 返回函数指针方式2，后置声明
auto foo2() -> int (*)(int)
{
    return bar_impl;
}

void demo1()
{
    cout << "> demo1" << endl;
    auto f1 = foo1();
    auto f2 = foo2();
    cout << f1(12) << endl;
    cout << f2(89) << endl;
}

// 2. 推导函数模版返回类型
template <class T1, class T2>
auto sum1(T1 t1, T2 t2) -> decltype(t1 + t2)
{
    return t1 + t2;
}

void demo2()
{
    cout << "> demo2" << endl;
    cout << sum1(2, 3) << endl;
}

int main()
{
    demo1();
    demo2();
}