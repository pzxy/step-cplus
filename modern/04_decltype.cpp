#include <iostream>
using namespace std;

void demo1()
{
    cout << "> demo1" << endl;
    int a = 0;
    // typeof是GCC编译器的扩展
    typeof(a) b = 5;
    // typeid 是c++标准,不过并不能像typeof那样在编译期就确定对象类型
    int x = 2;
    std::cout << typeid(x).name() << std::endl;
}

void demo2()
{
    cout << "> demo2" << endl;
    // 1. decltype 在编译期推导表达式的类型。
    int x1 = 0;
    decltype(x1) x2 = 0;
    std::cout << typeid(x2).name() << std::endl; // x2的类型为int
    double x3 = 0;
    decltype(x1 + x3) x4 = x1 + x3;
    std::cout << typeid(x4).name() << std::endl; // x1+x3的类型为
    // double decltype({1, 2}) x5;                  // 编译失败，{1, 2}不是表达式

    // 2. auto不能在非静态成员变量中使用。decltype可以。
    struct S1
    {
        int x1;
        decltype(x1) x2;
        double x3;
        decltype(x2 + x3) x4;
    };
    // 3. 不能在参数列表中使用。decltype可以。
    // int x1 = 0;
    // decltype(x1) sum(decltype(x1) a1, decltype(a1) a2)
    // {
    //     return a1 + a2;
    // };
    // auto x2 = sum(5, 10);
}
// C++ 11，auto返回类型不能直接推导，要使用后置类型推导。
auto sum(int a1, int a2) -> int
{
    return a1 + a2;
}
// 如果使用模版，需要这样写
template <class T1, class T2>
auto sum2(T1 a1, T2 a2) -> decltype(a1 + a2)
{
    return a1 + a2;
}

// c++14以后可以直接用
template <class T1, class T2>
auto sum3(T1 a1, T2 a2)
{
    return a1 + a2;
}

void demo3()
{
    cout << "> demo3" << endl;
    cout << sum(1, 2) << endl;
    cout << sum2(2, 3) << endl;
    cout << sum3(3, 4) << endl;
}

// return_ref 返回 t而不是 &t，return_ref2返回&t
template <class T>
auto return_ref(T &t)
{
    return t;
}
template <class T>
auto return_ref2(T &t) -> decltype(t)
{
    return t;
}
// decltype(auto) 非类型模版，和return_ref2是一样的效果。
template <class T>
decltype(auto) return_ref3(T &t)
{
    return t;
}

void demo4()
{
    cout << "> demo4" << endl;
    int x1 = 0;
    // 编译错误，返回值不为引用类型; 因为 return_ref 返回值是 auto t,不是 auto &t ，auto t这种写法是值类型的。
    // static_assert(std::is_reference_v<decltype(return_ref(x1))>);
    // 编译成功
    static_assert(std::is_reference_v<decltype(return_ref2(x1))>);
    static_assert(std::is_reference_v<decltype(return_ref3(x1))>);
}

struct A
{
    double x;
};
void demo5()
{
    cout << "> demo5 基本推导规则" << endl;
    // 1. 如果e是一个未加括号的标识符表达式（结构化绑定除外）或者未加括号的类成员访问，则decltype(e)推断出的类型是e的类型T。
    // 如果并不存在这样的类型，或者e是一组重载函数，则无法进行推导。
    // 2．如果e是一个函数调用或者仿函数调用，那么decltype(e)推断出的类型是其返回值的类型。
    // 3．如果e是一个类型为T的左值，则decltype(e)是T&。
    // 4．如果e是一个类型为T的将亡值，则decltype(e)是T&&。
    // 5．除去以上情况，则decltype(e)是T。
    const int &&foo();

    int i;
    const A *a = new A();
    decltype(foo());  // decltype(foo())推导类型为const int&&， 规则2，4
    decltype(i);      // decltype(i)推导类型为int 规则 1
    decltype(a->x);   // decltype(a->x)推导类型为double 规则1
    decltype((a->x)); // decltype((a->x))推导类型为const double& 规则 3

    // 总结
    // 1. 函数推导返回值
    // 2. 常量本值，左值T&，右值T&&
}

void demo6()
{
    cout << "> demo6 cv限定符推导" << endl;
    // decltype(e)所推导的类型会同步e的cv限定符
    const int i = 0;
    const A *a = new A();
    decltype(i);      // decltype(i)推导类型为const int
    decltype(a->x);   // decltype(a->x)推导类型为double 规则1，类似这种的，cv限定符会被忽略
    decltype((a->x)); // decltype((a->x))推导类型为const double& 规则 3
}

// decltype(auto),这样就不用向上面一样写后置类型推导了。
void demo7()
{
    cout << "> demo7 decltype(auto)" << endl;
    // decltype(auto) 其实就是auto用decltype的推导规则。
    int i = 9;
    auto x2a = (i);           // x2a推导类型为int,auto 推导成int
    decltype(auto) x2d = (i); // x2d推导类型为int&，decltype(auto)用的 decltype 推导规则，推导成 int&
}

int main()
{
    demo1();
    demo2();
    demo3();
    demo4();
    demo5();
    demo6();
    demo7();
}

// 总结：
// auto 推导类似一种占位符。
// const int i = 5; auto &m = i; auto推导类型为const int，m推导类型为const int&
// 很直观的能看出来，const int用auto占位了。
// auto 常用于迭代器遍历，模版函数返回类型推导，lambda表达式。
// 不能在机构体中当变量类型，如果当需要是静态常量

// decltype 推导复杂，规则如下
// 1. 函数推导返回值
// 2. 常量本值，左值推导T&，右值推导T&&
// 推导的时候不是简单的占位，会在原类型基础上进行转换。
// 可以在结构体中当变量类型。

