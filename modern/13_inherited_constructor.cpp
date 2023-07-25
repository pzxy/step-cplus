#include <iostream>
using namespace std;
// 引入基类的构造函数。
class Base
{
public:
    Base() : x_(0), y_(0.){};
    Base(int x, double y) : x_(x), y_(y) {}
    Base(int x) : x_(x), y_(0.) {}
    Base(double y) : x_(0), y_(y) {}

private:
    int x_;
    double y_;
};
class Derived : public Base
{
public:
    using Base::Base;
};
// 注意事项
// 1. 因为派生类是隐式继承基类的构造函数，所以只有在程序中使用了这些构造函数，编译器才会为派生类生成继承构造函数的代码。
// 2. 派生类不会继承基类的默认构造函数和复制构造函数。因为调用派生类的这两个函数的时候，都会优先调用基类的相同函数，因此继承这两个函数是多余的。
// 3. 派生类依然会生成自己的默认构造函数。
// 4. 派生类中有签名相同的构造函数，会使用派生类中的构造函数，不会继承基类中的签名相同构造函数。但不影响其他函数的继承。（c++11之前的编译器可能有例外，这点要看书，或者试一下）
class Base4
{
public:
    Base4() : x_(0), y_(0.){};
    Base4(int x, double y) : x_(x), y_(y) {}
    Base4(int x) : x_(x), y_(0.) { std::cout << "Base4(int x)" << std::endl; }
    Base4(double y) : x_(0), y_(y) { std::cout << "Base4(double y)" << std::endl; }

private:
    int x_;
    double y_;
};
class Derived4 : public Base4
{
public:
    using Base4::Base4;
    Derived4(int x) { std::cout << "Derived4(int x)" << std::endl; }
};

void demo4()
{
    cout << "> demo4" << endl;
    Derived4 d(5);
    Derived4 d2(5.6);
}
// 5. 派生类继承多个签名相同的构造函数会导致编译失败,比如继承的Base1和Base2中都有 "类名(int){}" 的构造函数。
// 6. 基类中的私有构造函数不能被继承。


// 总结：
// 以上主要是要使用基类中的构造函数的方式，如果我们不使用基类中的构造方法，则不用这样做。
int main()
{
    demo4();
}
