#include <iostream>
using namespace std;
// 思考学习方案，感觉没必要学习的太细。学的太细很多东西用不到，用到了可以再去书上找，只要知道有这么一个东西就行。
// 学的太细会花费更多的时间，不如将是将花费到收益更高的事情上去。
// 接下来定的学习方案是，重要的常用的做详细笔记，用不到的偏门的则一笔带过，知道有这么一个东西，但是不深究了，时间不够的。

// 1. 枚举类型的弊端
enum School
{
    student,
    teacher,
    principal
};
// 枚举类型可以隐式转换为整型，因为它默认底层类型就是int。不过c++11中可以指定类型。
// 枚举类型使用的时候可以不带枚举名来用，也就是 enum A{a,b,c}; 我们可以直接使用a，而无需说明A，这样会非常疑惑，特别是当枚举B中也有a时，会更迷惑。
// 以上2种弊端可以通过将枚举类型定义到类中，然后重写比较操作符来解决，不过要写很多代码，具体看书。

// 2. 使用强枚举类型
// 特点：
// 枚举标识符属于强枚举类型的作用域。
// 枚举标识符不会隐式转换为整型。
// 能指定强枚举类型的底层类型，底层类型默认为int类型。
enum class HighSchool
{
    student,
    teacher,
    principal
};
enum class University
{
    student,
    professor,
    principal
};
void demo2()
{
    cout << "> demo2" << endl;
    HighSchool x = HighSchool::student;
    University y = University::student;
    // bool b = x < y;// 不同的枚举不能比较。
    // std::cout << std::boolalpha << b << std::endl;
}

// C++11后无论是是枚举类型还是强枚举类型都能指定底层类型。
enum class E : unsigned int
{
    e1 = 1,
    e2 = 2,
    e3 = 0xfffffff0
};
enum E2 : unsigned int
{
    e1 = 1,
    e2 = 2,
    e3 = 0xfffffff0
};

// 3. C++17后，可以列表初始化有底层类型的枚举对象。
enum class Color
{
    Red,
    Green,
    Blue
};
// 如果是枚举类型，要使用初始化列表，必须指定底层类型。例如这里Color2就无法使用初始化列表。
enum Color2
{
    Red2,
    Green2,
    Blue2
};

enum Color3 : unsigned int
{
    Red,
    Green,
    Blue
};
void demo3()
{
    cout << "> demo3" << endl;
    Color c{5}; // 编译成功,只可以列表初始化
    //     Color c1 = 5;   // 编译失败
    //     Color c2 = {5}; // 编译失败
    //     Color c3(5);    // 编译失败
    Color2 c2{6};
    Color3 c3{6};
}

// 4. 使用using打开强枚举类型
const char *ColorToString(Color c)
{
    switch (c)
    {
        // 因为这里将Color引入到了switch中了，因此直接使用里面的枚举值，而不用Color::Red这样来使用了。
        using enum Color;
    case Red:
        return "Red";
    case Green:
        return "Green";
    case Blue:
        return "Blue";
    default:
        return "none";
    }
}
int main()
{
    demo2();
    demo3();
}
