#include <iostream>
using namespace std;
// 从c++11开始有这个关键字了
// 1. 使用noexcept 代替 throw
// 复制构造函数，复制过程中抛出异常，并不影响原数据，因为是拷贝操作。
// 11又了移动构造以后，移动构造的时候可能抛出异常，抛出异常时，可能移动了一半，会影响原数据。
// 因此需要让编译器在移动构造的时候，如果发生异常，需要直接结束程序，防止程序继续的错误运行下去。
// 所以增加了 noexcept关键字，告诉编译器，这个方法不会发生异常，如果发生了异常，应该调用std::terminate去结束程序。
// 没有加noexcept的函数，c++会加上额外的处理异常的代码。导致二进制包变大，除非特别关心这个，比如写一个lib包，否则加不加其实问题不大。
// 1.1 基本例子，声明下面的方法不会抛出异常，编译器在编译阶段会对值进行优化。
struct X
{
    int f() const noexcept
    {
        return 58;
    }
    void g() noexcept {}
};
int foo() noexcept
{
    return 42;
}

// 1.2 接受boolean返回值，true相当于不带参数，false则说明可能抛出异常。
// std::is_fundamental来判断T是否为基础类型，如果T是基础类型则不会抛出异常，否则有可能抛出异常。
template <class T>
T copy(const T &o) noexcept(std::is_fundamental<T>::value)
{
}

// 1.3 还可以传入表达式。
// int foo() noexcept
// {
//     return 42;
// }
int foo1()
{
    return 42;
}
int foo2() throw()
{
    return 42;
}
// 实际上编译时，表达式并不会执行，只是在做可能的判断。
// noexcept(foo()) = true ，foo表示 noexcept 则说明肯定不会有异常，所以保持默认值，返回true
// noexcept(foo1()) = false，foo1没有加noexcept,说明可能有异常。
// noexcept(foo2()) = true，foo2 将异常抛出了，也就是说foo2如果发生异常了，也不用调用std::terminate终止程序，因此也属于没有异常。

// 2. 用noexcept来解决移动构造问题，感觉用不上，略。

// 3. noexcept 和 throw
// 用 noexcept 运算符去探测 noexcept和throw()声明的函数，会返回相同的结果。
// noexcept 标记的的方法抛出异常，直接停止程序。throw()抛出异常，需要展开堆栈，然后调用std::unexpected
// 因此 noexcept比throw()有更好的性能。
// c++17中只有throw()是noexcept的别名，也就是说两个是一个东西。
// c++17中只有throw()被保留，其他任何形式的throw都不允许。
// c++20开始throw()也被移除。

// 4. 默认使用noexcept的函数。
// 基本上默认生成的都是。包括：默认构造，默认复制构造，默认赋值，默认移动构造，默认移动赋值。
// 下面输出全是 true，也就是说默认都加了 noexcept
struct X4
{
};
// 如果组合了其他的对象了，但是这些对象的构造方法中有的没有加 noexcept，那么会影响到自己。
struct M
{
    M() {}
    M(const M &) {}
    M(M &&) noexcept {}
    M operator=(const M &) noexcept { return *this; }
    M operator=(M &&) { return *this; }
};
struct Y4
{
    M m;
};
#define PRINT_NOEXCEPT(x) \
    std::cout << #x << " = " << x << std::endl

void demo4()
{
    cout << ">> demo4" << endl;
    cout << ">> X4" << endl;
    X4 x;
    std::cout << std::boolalpha;
    PRINT_NOEXCEPT(noexcept(X4()));
    PRINT_NOEXCEPT(noexcept(X4(x)));
    PRINT_NOEXCEPT(noexcept(X4(std::move(x))));
    PRINT_NOEXCEPT(noexcept(x.operator=(x)));
    PRINT_NOEXCEPT(noexcept(x.operator=(std::move(x))));
    cout << ">> Y4" << endl;
    Y4 y;
    PRINT_NOEXCEPT(noexcept(Y4()));
    PRINT_NOEXCEPT(noexcept(Y4(y)));
    PRINT_NOEXCEPT(noexcept(Y4(std::move(y))));
    PRINT_NOEXCEPT(noexcept(y.operator=(y)));
    PRINT_NOEXCEPT(noexcept(y.operator=(std::move(y))));
}
// 析构函数，以及使用=delete的函数，都带有 noexcept。包括自己实现的析构函数，以及delete函数。


// 5. 使用noexcept的时机
// 一旦使用了noexcept就要保证不会抛出异常，包括后面的修改。
// 5.1 保证不抛出异常的函数，例如对基本类型的初始化。获取成员变量的函数。
int main()
{
    demo4();
}