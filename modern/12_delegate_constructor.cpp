#include <iostream>
#include <list>
#include <vector>
using namespace std;
// 委托构造函数
// 1. 冗余的构造函数
// 常见的构造函数，依赖于CommonInit()
class X
{
public:
    X() : a_(0), b_(0.) { CommonInit(); }
    X(int a) : a_(a), b_(0.) { CommonInit(); }
    X(double b) : a_(0), b_(b) { CommonInit(); }
    X(int a, double b) : a_(a), b_(b) { CommonInit(); }

private:
    void CommonInit() {}
    int a_;
    double b_;
};
// 继续优化，将参数放到 CommonInit中。
class X1
{
public:
    X1() { CommonInit(0, 0.); }
    X1(int a) { CommonInit(a, 0.); }
    X1(double b) { CommonInit(0, b); }
    X1(int a, double b) { CommonInit(a, b); }

private:
    void CommonInit(int a, double b)
    {
        a_ = a;
        b_ = b;
    }
    int a_;
    double b_;
};
// 上面的还可以，但是如果成员函数中包含复杂的对象，那么就可能引发不确定问题。
// 下面的std::string类型的对象c_看似是在
// CommonInit函数中初始化为hello world，但是实际上它并不是
// 一个初始化过程，而是一个赋值过程。因为对象的初始化过程早在构
// 造函数主体执行之前，也就是初始化列表阶段就已经执行了。所以这
// 里的c_对象进行了两次操作，一次为初始化，另一次才是赋值为hello
// world，很明显这样对程序造成了不必要的性能损失
class X2
{
public:
    X2() { CommonInit(0, 0.); }
    X2(int a) { CommonInit(a, 0.); }
    X2(double b) { CommonInit(0, b); }
    X2(int a, double b) { CommonInit(a, b); }

private:
    void CommonInit(int a, double b)
    {
        a_ = a;
        b_ = b;
        c_ = "hello world";
    }
    int a_;
    double b_;
    std::string c_;
};

// 继续优化，通过为构造函数提供默认参数的方法来解决代码冗余的问题
// 但是作用有限，X3(double b)这个构造函数依然需要在初始化列表中重复初始化成员变量
class X3
{
public:
    X3(double b) : a_(0), b_(b) { CommonInit(); }
    X3(int a = 0, double b = 0.) : a_(a), b_(b) { CommonInit(); }

private:
    void CommonInit() {}
    int a_;
    double b_;
};
// 还有一种情况，这里略过。

// 2. 委托构造函数
// 为了方面描述。X(是委托构造函数)：X(是代理构造函数，英文直译目标构造函数)
// 执行顺序：
// 代理构造函数的初始化列表->代理构造函数的主体(也就是CommonInit函数)->委托构造函数的主体
class X20
{
public:
    X20() : X20(0, 0.) {}
    X20(int a) : X20(a, 0.) {}
    X20(double b) : X20(0, b) {}
    X20(int a, double b) : a_(a), b_(b) { CommonInit(); }

private:
    void CommonInit() {}
    int a_;
    double b_;
};

// 合理使用委托构造函数的注意事项：
// 2.1 可能存在一个构造函数，它既是委托构造函数也是代理构造函数，X(int a)
class X21
{
public:
    X21() : X21(0) {}
    X21(int a) : X21(a, 0.) {}
    X21(double b) : X21(0, b) {}
    X21(int a, double b) : a_(a), b_(b) { CommonInit(); }

private:
    void CommonInit() {}
    int a_;
    double b_;
};

// 让特殊构造函数X210(const X &other)成为委托构造函数
class X210
{
public:
    X210() : X210(0) {}
    X210(int a) : X210(a, 0.) {}
    X210(double b) : X210(0, b) {}
    X210(int a, double b) : a_(a), b_(b) { CommonInit(); }
    X210(const X210 &other) : X210(other.a_, other.b_) {} // 委托复制构造函数
private:
    void CommonInit() {}
    int a_;
    double b_;
};

// 2.2 不要递归循环委托，编译器不会报错，运行时才会报错，栈溢出错误
// X22->X22(a)->X22(a,b)->X22
class X22
{
public:
    X22() : X22(0) {}
    X22(int a) : X22(a, 0.) {}
    X22(double b) : X22(0, b) {}
    X22(int a, double b) : X22() { CommonInit(); }

private:
    void CommonInit() {}
    int a_;
    double b_;
};

// 2.3 如果一个构造函数为委托构造函数，那么其初始化列表里就不能对数据成员和基类进行初始化
// class X23
// {
// public:
//     X23() : a_(0), b_(0) { CommonInit(); }
//     X23(int a) : X23(), a_(a) {}    // 编译错误，委托构造函数不能在初始化列表初始化成员变量
//     X23(double b) : X23(), b_(b) {} // 编译错误，委托构造函数不能在初始化列表初始化成员变量
// private:
//     void CommonInit() {}
//     int a_;
//     double b_;
// };

// 2.4 委托构造函数的执行顺序: 代理构造函数的初始化列表->代理构造函数的主体->委托构造函数的主体
// 顺序要好好梳理一下
// X x 的输出顺序如下：
// InitStep1()
// InitStep2()
// InitStep3()

class X24
{
public:
    X24() : X24(0) { InitStep3(); }
    X24(int a) : X24(a, 0.) { InitStep2(); }
    X24(double b) : X24(0, b) {}
    X24(int a, double b) : a_(a), b_(b) { InitStep1(); }

private:
    void InitStep1() { std::cout << "InitStep1()" << std::endl; }
    void InitStep2() { std::cout << "InitStep2()" << std::endl; }
    void InitStep3() { std::cout << "InitStep3()" << std::endl; }
    int a_;
    double b_;
};

// 2.5 如果在代理构造函数执行完成后，委托构造函数主体抛出了异常，则自动调用该类型的析构函数
// 这里很好理解，用一句话来说就是，代理构造函数，也是构造函数。调用析构函数没毛病。

// 3. 委托模版构造函数。
// 在上面的代码中template<class T> X(T first, T last)是一个代理模板构造函数，X(std::vector<short>&)和
// X(std::deque<int>&)将控制权委托给了它。这样一来，我们就无须编写std::vector<short>和std::deque <int>版本的代理构造函数。
// 后续增加委托构造函数也不需要修改代理构造函数，只需要保证参数类型支持迭代器就行了。
class X30
{
    template <class T>
    X30(T first, T last) : l_(first, last) {}
    std::list<int> l_;

public:
    X30(std::vector<short> &);
    // X30(std::deque<int> &);
};
X30::X30(std::vector<short> &v) : X30(v.begin(), v.end()) {}
// X30::X30(std::deque<int> &v) : X30(v.begin(), v.end()) {}

void demo3()
{
    cout << "> demo3" << endl;
    std::vector<short> a{1, 2, 3, 4, 5};
    X30 x1(a);
};
// 4. 捕获委托构造函数的异常,代码在书上，不过也很容易理解的。
// X()委托到X(int a)，X(int a)委托到X(int a, double b)。因此在X(int a,double b)发生异常的时候，会以相反的顺序抛出异常

// 5. 委托参数较少的构造函数。
// 经验：将参数较少的构造函数委托给参数较多的构造函数。
// 通常情况下我们建议这么做，因为这样做的自由度更高。
// 建议这样做，但不是一定要这样做。具体情况具体分析。
int main()
{
    demo3();
}