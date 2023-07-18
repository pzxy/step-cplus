#include <iostream>
using namespace std;
// 1. 基本语法
// 定义 [ captures ]<typename T> ( params ) specifiers exception -> ret { body }
// <typename T> 一般用不到。
// specifiers 可选限定符 mutable、const等
// exception 可选异常说明符 noexcept
// ret 可选返回值类型。不写则返回 void

// 2. 捕获列表
// 2.1 作用域
// 2.2 捕获值和捕获引用 捕获值[x,y]{return x*y}; 捕获引用[&x,&y]{return x*y};
void demo2()
{
    cout << "> demo2" << endl;
    int x = 5, y = 10;
    // 编译报错，不能修改
    // auto foo = [x, y]
    // {
    //     x += 1;
    //     y += 2;
    //     return x * y;
    // };
    auto foo = [x, y]() mutable // 增加mutable可以修改,并不影响原本的值。引用的话，会影响原本的值。
    {
        x += 1;
        y += 2;
        return x * y;
    };
    cout << x << endl;
    cout << foo() << endl;
}
// 2.3. 特殊的捕获方法
// [this] 捕获this指针，可以让我们使用this类型的成员变量。
// [=] 捕获上下文全部变量的值。是值不是引用。
// [&] 捕获上下文的全部变量的引用，包括this

// 3.  lambda表达式的实现原理
// 定义lambda表达式，然后用GCC输出器GIMPLE的中间代码。
// 会看出是自定义()运算符，正是函数对象类型的特性。所以lambda只是一个语法糖而已。
// lambda表达式功能完全能够手动实现。只不过lambda表达式让代码编写更加轻松了。

// 4. 无状态的lambda表达式。
// 无状态的lambda表达式可以转换成函数指针。
void f(void (*)()) {}
void g()
{
    f([] {});
} // lambda表达式[] {}隐式转换为void(*)()类型的函数指针，可以编译成功

void f2(void (&)()) {}
void g2()
{
    f(*[] {});
} // 可以编译成功

// 5. 在STL中使用lambda表达式
// std::vector<int> x = {1, 2, 3, 4, 5};
// std::find_if(x.cbegin(), x.cend(), [](int i){ return (i % 3) == 0; })

// 6. 广义捕获(C++14)
// 第一种，简单捕获 [x] ,[&x],[this]等  ，this表示指向对象的指针，*this表示对象本身。
// 第二种，初始化捕获。 [x = x + 1] 和 [r = x + 1]是一个意思。
void demo6()
{
    cout << "> demo6" << endl;
    int x = 5;
    auto foo = [r = x + 1]
    { return r; };
    cout << "x: " << x << endl;
    cout << "r: " << foo() << endl;

    // 使用move，提高性能
    std::string s = "hello c++ ";
    auto foo2 = [s = std::move(s)]
    { return s + "world"; };
    cout << foo2() << endl;

    // 避免多线程影响
    // 多线程捕获[=]直接使用对象中的值，可能使用的时候对象已经被析构。
    // 使用[=,tmp = *this] 相当于复制了一份*this到了tmp中，然后使用tmp的值。
}

// 7. 泛型lambda表达式
void demo7()
{
    cout << "> demo7" << endl;
    auto foo = [](auto a)
    { return a; };
    int three = foo(3);
    // auto s = foo("hello");
    char const *s = foo("hello");
    cout << s << endl;
}

// 8. 常量lambda表达式和捕获*this
// 6中使用 [=,tmp = *this] 的方式复制对象然后捕获。
// C++17中，提供了[=,*this]的方式可以直接捕获复制对象。

// 9. 捕获[=,this]
// c++20之前使用[=]就是捕获this，c++20以后必须使用[=,this]才算是捕获this。
// 也就是说c++20以后标准已经不支持[=]隐式捕获this指针了。

// 10. 模版语法的泛型lambda表达式。

int main()
{
    demo2();
    demo6();
    demo7();
}
