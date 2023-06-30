#include <iostream>
using namespace std;

// 比起声明函数为private但不定义，使用deleted函数更好
// 任何函数都能被删除（be deleted），包括非成员函数和模板实例（译注：实例化的函数）

// 1. 禁用普通函数中一些意料之外的函数。C++有沉重的C包袱，使得含糊的、能被视作数值的任何类型都能隐式转换为int，但是有一些调用可能是没有意义的：
// if (isLucky('a')) …         //字符'a'是幸运数？
// if (isLucky(true)) …        //"true"是?
// if (isLucky(3.5)) …         //难道判断它的幸运之前还要先截尾成3？
bool isLucky(int number)
{
    if (number > 100)
    {
        return true;
    }
    return false;
}
// 不允许char类型和bool类型的数据
bool isLucky(char) = delete;
bool isLucky(bool) = delete;

void demo1()
{
    cout << "> demo1" << endl;
    cout << isLucky(200) << endl;
    // cout << isLucky('p') << endl;
    // cout << isLucky(true) << endl;
}

// 2. 不允许调用父类的一些方法。
class A
{
public:
    void set()
    {
        cout << "A: set" << endl;
    }
    void get()
    {
        cout << "B: set" << endl;
    }
};

class B : public A
{
public:
    void get() = delete;
};

void demo2()
{
    cout << "> demo2" << endl;
    B b;
    b.set();
    // b.get();
};

// 3. 禁用模版中一些意料之外模版匹配。
template <typename T>
void processPointer(T *ptr); // 原始指针，一般建议使用智能指针。
// 在指针的世界里有两种特殊情况。一是void*指针，因为没办法对它们进行解引用，或者加加减减等。
// 另一种指针是char*，因为它们通常代表C风格的字符串，而不是正常意义下指向单个字符的指针。
// 这两种情况要特殊处理，在processPointer模板里面，我们假设正确的函数应该拒绝这些类型。
// 也即是说，processPointer不能被void*和char*调用。
template <>
void processPointer<void>(void *) = delete;
template <>
void processPointer<char>(char *) = delete;

// const void*和const char*也应该无效，所以这些实例也应该标注delete
template <>
void processPointer<const void>(const void *) = delete;
template <>
void processPointer<const char>(const char *) = delete;

// 如果你想做得更彻底一些，你还要删除const volatile void*和const volatile char*重载版本
// 另外还需要一并删除其他标准字符类型的重载版本：std::wchar_t，std::char16_t和std::char32_t。

// 4. 如果模版在一个类中，如何禁用？
// class Widget
// {
// public:
//     template <typename T>
//     void processPointer(T *ptr);
// private:
//     template <> // 错误,模板特例化必须位于一个命名空间作用域，而不是类作用域。 这里同一个模版特化不能又在public中又在private中。
//     void processPointer<void>(void *);// 这里编译就会报错。
// };
// 但是，delete没有这个问题。所以应该这样写：
class Widget
{
public:
    template <typename T>
    void processPointer(T *ptr);
};
template <>                                         // 还是public，
void Widget::processPointer<void>(void *) = delete; // 但是已经被删除了

int main()
{
    demo1();
    demo2();
}
