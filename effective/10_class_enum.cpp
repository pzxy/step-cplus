#include <iostream>

using namespace std;

// 使用 class enum 而不是 enum
int main()
{
    // 1. class enum的作用域更小
    // 1.1 enum
    enum Color
    {
        black,
        white,
        red
    };                  // black, white, red在
                        // Color所在的作用域
    auto white = false; // 错误! white早已在这个作用
    // 域中声明
    // 1.2 class enum
    enum class Color
    {
        black,
        white,
        red
    };                  // black, white, red
                        // 限制在Color域内
    auto white = false; // 没问题，域内没有其他“white”

    Color c = white; // 错误，域中没有枚举名叫white

    Color c = Color::white; // 没问题
    auto c = Color::white;  // 也没问题（也符合Item5的建议）

    // 2. class enum中的数据是强类型的，enum有隐士转换为整型，或者浮点数，甚至char类型。
    // 2.1 enum
    enum Color
    {
        black,
        white,
        red
    }; // 未限域enum，可以隐式转换成整型

    std::vector<std::size_t> // func返回x的质因子
    primeFactors(std::size_t x);

    Color c = red;

    if (c < 14.5)
    {                  // Color与double比较 (!)
        auto factors = // 计算一个Color的质因子(!)
            primeFactors(c);
    }
    // 2.2 class enum 类型，不可以隐式转换，不要强转才行。
    enum class Color
    {
        black,
        white,
        red
    }; // Color现在是限域enum

    Color c = Color::red;                              // 和之前一样，只是
                                                       // 多了一个域修饰符
    if (static_cast<double>(c) < 14.5)                 // 需要强转
    {                                                  // 奇怪的代码，
                                                       // 但是有效
        auto factors =                                 // 有问题，但是
            primeFactors(static_cast<std::size_t>(c)); // 能通过编译
    }

    // 3. 前置声明 class enum可以前置声明，因为他的类型是确定的，enum不能直接前置声明(但是如果有底层类型的话，是可以的)
    enum Color;       // 错误！
    enum class Color; // 没问题

    // 4. enum 比 class enum唯一的好处。配合元组使用。
    using UserInfo =               // 类型别名，参见Item9
        std::tuple<std::string,    // 名字
                   std::string,    // email地址
                   std::size_t>;   // 声望
    UserInfo uInfo;                // tuple对象
    auto val = std::get<1>(uInfo); // 获取第一个字段，使用get<1>

    enum UserInfoFields
    {
        uiName,
        uiEmail,
        uiReputation
    };

    UserInfo uInfo;                      // 同之前一样
    auto val = std::get<uiEmail>(uInfo); // 啊，获取用户email字段的值,枚举值获取数据。

    // 总结：
    //     C++98的enum即非限域enum。
    // 限域enum的枚举名仅在enum内可见。要转换为其它类型只能使用cast。
    // 非限域/限域enum都支持底层类型说明语法，限域enum底层类型默认是int。非限域enum没有默认底层类型。
    // 限域enum总是可以前置声明。非限域enum仅当指定它们的底层类型时才能前置。
}