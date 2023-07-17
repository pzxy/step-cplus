#include <iostream>
using namespace std;
// 1. 左值，右值
// 在C++中所谓的左值一般是指一个指向特定内存的具有名称的值（具名对象），它有一个相对稳定的内存地址，并且有一段较长的生命周期。
// 而右值则是不指向稳定内存地址的匿名值（不具名对象），它的生命周期很短，通常是暂时性的。
// 基于这一特征，我们可以用取地址符&来判断左值和右值，能取到内存地址的值为左值，否则为右值

void demo1()
{
    cout << "> demo1" << endl;
    int x = 3;
    // int *p = &x++; // 编译失败，因为x++是右值，不能取地址
    int *q = &++x;
    // auto i = &4; // 失败，字面量是右值。
    auto s = &"hello world"; // 成功，因为字符串加载的时候会开辟空间，也就是左值。
}

// 2. 右值引用 &
// 3. 右值应用 &&
// 4. 右值的性能优化空间，复制变为移动，可以提高接近2倍的性能。
// 5. 移动语义，复制构造->移动构造
// 6. 值类别
// 将亡值(xvalue)：临时的值
// int b = X().a ;这里的X()就是将亡值。
// 7. 左值转右值
void demo7()
{
    cout << "> demo7" << endl;
    int i = 0;
    // 下面两种方式效果是一样的。
    int &&k = static_cast<int &&>(i);
    int &&j = std::move(i);
}

// 8. 万能引用和引用折叠
// 第一种万能引用，模版
template <class T>
void bar(T &&t){}; // t为万能引用,也就是说传左值和右值都可以。
// 第二种万能引用，模版
// auto &&y = get_val();
// 可以看出来两种万能引用，都发生了类型推导。
// 总结： 万能引用必须是 T&& 或者 auto&&

// 万能引用会引用折叠，引用折叠的规则如下：
// 1. 如果模版类型为T&，无论实际类型是什么，最终类型都是T&
// 2. 如果模版类型为T&&，实际类型是R&，则最终类型是T&。如果实际类型是其他类型则都是T&&。
// 总结：只要实际类型是R&则最终类型就是R&，其他情况模版类型和最终类型一致。
// 总结：参数是左值，则左值，参数是其他，则和模版引用类型一致。

// 9. 完美转发(万能引用的用途)
// 完美转发减少了不必要的复制，提高了代码性能。
template <class T>
void show_type(T t) // 效率很低，按值传入，全部拷贝。
{
    std::cout << typeid(t).name() << std::endl;
}
template <class T>
void perfect_forwarding(T &&t) // 效率高，引用传递，传左值，右值都可以。
{
    show_type(static_cast<T &&>(t));
}
template <class T>
void perfect_forwarding2(T &&t)
{
    show_type(std::forward<T>(t)); // std::forward 替代 static_cast
}

void demo9()
{
    cout << "> demo9" << endl;
    perfect_forwarding(1);
    perfect_forwarding2(1);
}

// 10. 针对局部变量和右值引用的隐式移动操作
struct X
{
    X() = default;
    X(const X &) = default;
    X(X &&)
    {
        std::cout << "move ctor" << std::endl;
    }
};
X f(X x)
{
    return x;
}

X f2()
{
    X x;
    return x;
}

X f3(X &&x)
{
    return x;
}
X f4(X &&x)
{
    return std::move(x);
}
// c++20 中，如何下面的情况会使用移动语义
// return或者co_return语句中的返回对象是函数或者lambda表达式中的对象或形参。
// throw语句中抛出的对象是函数或try代码块中的对象
void f5()
{
    X x;
    throw x;
}

void demo10()
{
    cout << "> demo10" << endl;
    cout << "> demo10 r" << endl;
    X r = f(X{}); // 输出 move ctor ，移动构造
    cout << "> demo10 r2" << endl;
    X r2 = f2(); // 输出 move ctor, 编译时增加 -fno-elide-constructors 关闭返回值优化，不关闭的话，会用返回值优化替代移动构造。
    cout << "> demo10 r3" << endl;
    X r3 = f3(X{}); // 不会优化，因为f3行参是左值，调用复制构造。
    cout << "> demo10 r4" << endl;
    X r4 = f4(X{}); // 输出 move ctor，通过std::move优化 f3.
    cout << "> demo10 r5" << endl;
    try
    {
        f5(); // 输出  move ctor，try catch捕获的这个x就是西东构造。
    }
    catch (exception e)
    {
    }
}

int main()
{
    demo1();
    demo7();
    demo9();
    demo10();
}