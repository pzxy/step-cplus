#include <iostream>
using namespace std;
// 1. 回顾变量初始化
// int x = 5;拷贝初始化
void demo()
{
    cout << "> demo" << endl;
    int x = 5; // 拷贝初始化
    int y{10}; // 直接初始化
}

// 2. 列表初始化,就是使用{}来初始化。
// 如果不使用 = 号, int x = {5}，不使用{}作为参数 f({}),则 {} 都是直接初始化。

// 3. std::initializer_list 详解
// 标准容器为什么支持 initializer_list？
// - std::initializer_list简单地说就是一个支持begin、end以及size成员函数的类模板
// - 编译器负责将列表里的元素（大括号包含的内容）构造为一个std::initializer_list的对象，然后寻找标准容器中支持std:: initializer_list为形参的构造函数并调用它
// 例子：
struct C
{
    C(std::initializer_list<std::string> a)
    {
        for (const std::string *item = a.begin(); item != a.end();
             ++item)
        {
            std::cout << *item << " ";
        }
        std::cout << std::endl;
    }
};
void demo3()
{
    cout << "> demo3" << endl;
    C c{"hello", "c++", "world"};
    // 书里面进一步举例说明，这里的初始化列表就是一个字符串数组。
}

// 4. 使用列表初始化的注意事项。
// 4.1 隐式缩窄转换问题，就是不同数值类型直接转换，比如int转char，int，double这些。
// 4.2 列表初始化的优先级问题。
// 如果有一个类同时拥有满足列表初始化的构造函数，且其中一个是以std::initializer_list为参数，
// 那么编译器将优先以 std::initializer_ list为参数构造函数

// 5. 指定初始化
// 要求对象必须是一个聚合类型：
// - 无自定义构造函数；
// - 非静态数据成员没有大括号或等号初始化器，即类内没有初始值；
// - 无私有或保护的非静态成员；
// - 无基类和虚函数。
struct Point
{
    int x;
    int y;
    int z;
};
void demo5()
{
    cout << "> demo5" << endl;
    // 必须顺序指定，因为c++中初始化时是顺序初始化的。
    Point p{.x = 4, .y = 5};
    cout << p.z << endl;
}
int main()
{
    demo();
    demo3();
    demo5();
}