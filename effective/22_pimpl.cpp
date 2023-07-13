#include <iostream>
#include <memory>
#include <vector>
using namespace std;
// 使用pimpl的方式，可以将头文件中导入的依赖转移到 实现的.cpp文件中。
// 在实现lib库的时候，是很常用的，可以避免引入不必要的头文件。
// 如果是在平时开发的应用中，并不关心引入库的问题，所以并不常用。

// 1. Pimpl惯用法通过减少在类实现和类使用者之间的编译依赖来减少编译时间。
// 2. 对于std::unique_ptr类型的pImpl指针，需要在头文件的类里声明特殊的成员函数，但是在实现文件里面来实现他们。即使是编译器自动生成的代码可以工作，也要这么做。
// 3. 以上的建议只适用于std::unique_ptr，不适用于std::shared_ptr。

class Widget
{ // 在“widget.h”中
public:
    Widget();
    // 没有析构函数和移动操作的声明

private:
    struct Impl;
    std::shared_ptr<Impl> pImpl; // 用std::shared_ptr
};                               // 而不是std::unique_ptr

// widget.cpp中实现
struct Widget::Impl
{ // 跟之前一样，定义Widget::Impl
    std::string name;
    std::vector<double> data;
};

Widget::Widget() //
    : pImpl(std::make_shared<Impl>())
{
}

int main()
{
    Widget w1;
    auto w2(std::move(w1)); // 移动构造w2
    w1 = std::move(w2);     // 移动赋值w1
}

// 总结： 使用 share_ptr 一定没问题。使用 unique_ptr 要在实现文件中声明特殊成语函数，及时编译器没报错。
// 关于这个unique_ptr，暂时我也没搞明白，大概是必须和析构的时候有关系，具体用到的时候再说吧。反正由于不觉的话，用shared_ptr肯定没错了。