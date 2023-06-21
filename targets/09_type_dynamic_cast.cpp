#include <iostream>
#include <vector>
using namespace std;
// static_cast 基本类型的转化 ，int->string等。也可进行父子类转换，但是不检查。并且static_cast是不会报错的。
// dynamic_cast 父子类之间的转换，会检查，如果转换失败返回空。
// reinterpret_cast
// const_cast
// any_cast

struct V
{
    virtual void f() {} // must be polymorphic to use runtime-checked dynamic_cast
};

struct A : virtual V
{
};

struct B : virtual V
{
    B(V *v, A *a)
    {
        // casts during construction (see the call in the constructor of D below)
        dynamic_cast<B *>(v); // well-defined: v of type V*, V base of B, results in B*
        dynamic_cast<B *>(a); // undefined behavior: a has type A*, A not a base of B
    }
};

struct D : A, B
{
    D() : B(static_cast<A *>(this), this) {}
};

struct Base
{
    virtual ~Base() {}
};

struct Derived : Base
{
    virtual void name() {}
};

void dynamic_cast_demo()
{
    cout << "> dynamic_cast_demo" << endl;
    D d;      // the most derived object
    A &a = d; // upcast, dynamic_cast may be used, but unnecessary

    [[maybe_unused]] D &new_d = dynamic_cast<D &>(a); // downcast
    [[maybe_unused]] B &new_b = dynamic_cast<B &>(a); // sidecast

    Base *b1 = new Base;
    if (Derived *d = dynamic_cast<Derived *>(b1); d != nullptr)
    {
        std::cout << "downcast from b1 to d successful\n";
        d->name(); // safe to call
    }

    Base *b2 = new Derived;
    if (Derived *d = dynamic_cast<Derived *>(b2); d != nullptr)
    {
        std::cout << "downcast from b2 to d successful\n";
        d->name(); // safe to call
    }

    delete b1;
    delete b2;
    // 总结：
    // 主要就是父子类型互转。
}

int main()
{
    dynamic_cast_demo();
}