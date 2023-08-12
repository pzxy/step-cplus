#include <iostream>
#include <string>
// C++17开始增强inline说明符
using namespace std;
// 1. 定义非常量静态成员变量的问题。
// 声明和定义必须分开进行。
class X
{
public:
    static std::string text;
};
std::string X::text{"hello"};
void demo()
{
    cout << ">> demo" << endl;
    X::text += " world";
    std::cout << X::text << std::endl;
}
// 错误的例子：定义在头文件中，include时，存在多份的话，会导致链接失败。
// #ifndef X_H
// #define X_H
// class X
// {
// public:
//     static std::string text;
// };
// std::string X::text{"hello"};
// #endif

// 2. 使用inline说明符，c++17开始可以静态变量。
class X2
{
public:
    // 这个挺好用的，rust中不能创建static变量，必须在unsafe中才可以。
    inline static std::string text{"hello"};
};
void demo2()
{
    cout << ">> demo2" << endl;
    X2::text += " world";
    std::cout << X::text << std::endl;
}
int main()
{
    demo();
    demo2();
}
