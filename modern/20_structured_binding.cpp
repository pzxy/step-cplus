#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
// C++17开始开始支持结构化绑定了。
// 1. 结构化绑定例子
auto return_multiple_values()
{
    return std::make_tuple(11, 7);
}

struct BindTest
{
    int a = 42;
    std::string b = "hello structured binding";
};

void demo()
{
    cout << "> demo" << endl;
    auto [x, y] = return_multiple_values();
    std::cout << "x=" << x << " y=" << y << std::endl;

    BindTest bt;
    auto [x2, y2] = bt;
    std::cout << "x2=" << x2 << " y2=" << y2 << std::endl;

    std::vector<BindTest> bt3{{11, "hello"}, {7, "c++"}, {42, "world"}};
    for (const auto &[x3, y3] : bt3)
    {
        std::cout << "x3=" << x3 << " y3=" << y3 << std::endl;
    }
}

// 2. 结构化绑定原理
// 原代码
// BindTest bt;
// const auto [x, y] = bt;
// 编译后伪代码，可以看到将原对象复制了一份。然后用auto来推导类型，最后赋值为了另外一个类型aliasname。
// BindTest bt;
// const auto _anonymous = bt;
// aliasname x = _anonymous.a
// aliasname y = _anonymous.b

// 3. 结构化绑定的三种类型。
// 3.1 绑定到原生数组。
// int a[3]{ 1, 3, 5 };
// auto[x, y, z] = a;

// 3.2 绑定到结构体和类对象
class BindBase1
{
public:
    int a = 42;
    double b = 11.7;
};
class BindTest1 : public BindBase1
{
};
class BindBase2
{
};
class BindTest2 : public BindBase2
{
public:
    int a = 42;
    double b = 11.7;
};
class BindBase3
{
public:
    int a = 42;
};
class BindTest3 : public BindBase3
{
public:
    double b = 11.7;
};

void demo3()
{
    cout << "> demo3" << endl;
    BindTest1 bt1;
    BindTest2 bt2;
    BindTest3 bt3;
    auto [x1, y1] = bt1; // 编译成功
    auto [x2, y2] = bt2; // 编译成功
    // auto [x3, y3] = bt3; // 编译错误,非静态数据成员要不全部定义在基类，要不全部定义在派生类才行。
}
// 3.3 绑定到元组和类元组的对象
// 元组、std::pair和std::array都可以作为绑定。
// 下面是pair
// for (const auto&[id, str]:id2str) {
//  std::cout << "id=" << id
//  << ", str=" << str << std::endl;
// }

// 3.4 并且我们可以自己实现一个类元组类型，这也可以结构化绑定了，这里略。

// 3.5 绑定的访问权限问题，实际上常见编译器C++17开始，都可以访问私有变量的。因此不用太关心这个访问权限问题。
int main()
{
    demo();
    demo3();
}