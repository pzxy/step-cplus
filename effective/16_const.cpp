#include <iostream>
#include <vector>

// 在C++中，使用`const`修饰类的成员方法可以使该方法成为常量成员函数。
// 常量成员函数不会修改类的数据成员，因此可以在常量对象上调用。
// 这样做可以提高代码的安全性和可读性。如果在常量对象上调用非常量成员函数，编译器会报错。

// 1. 确保const成员函数线程安全，除非你确定它们永远不会在并发上下文（concurrent context）中使用。
// 2. 使用std::atomic变量可能比互斥量提供更好的性能，但是它只适合操作单个变量或内存位置。 实际上这个很少用。

class A
{
public:
    void set(int i) const {
        // a = i;// 这里会报错，const成员方法只能读取，不能修改。及时读取，也要保证线程安全，因为不能保证读取的值

    };

private:
    int a;
};

class Polynomial
{
public:
    using RootsType = std::vector<double>;

    RootsType roots() const
    {
        if (!rootsAreValid)
        {                         // 如果缓存不可用
                                  // 计算根
                                  // 用rootVals存储它们
            rootsAreValid = true; // 这里因为有了 mutable修饰，所以在能在const成员方法中，改变 rootsAreValid 的值。
        }

        return rootVals;
    }

private:
    mutable bool rootsAreValid{false}; // 初始化器（initializer）的
    mutable RootsType rootVals{};      // 更多信息请查看条款7
};

int main()
{
    Polynomial p;
    auto rootsOfp = p.roots();
}