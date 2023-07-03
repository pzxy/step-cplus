#include <iostream>
using namespace std;
// 为重写函数加上override
// 成员函数引用限定让我们可以区别对待左值对象和右值对象（即*this)

// 1. 重新虚函数要加override
// 如果不加的话，也可以，但是如果写错了，编译器不一定警告，并且不同的编译器警告成都也不一样，所以为了保险，加上override就对了。
// 规则：
// 基类函数必须是virtual
// 基类和派生类函数名必须完全一样（除非是析构函数)
// 基类和派生类函数形参类型必须完全一样
// 基类和派生类函数常量性constness必须完全一样
// 基类和派生类函数的返回值和异常说明（exception specifications）必须兼容

// 2. 使用引用限定，为左值Widget和右值Widge写一个data的重载函数。
class Widget
{
public:
    using DataType = std::vector<double>;
    DataType &data() & // 对于左值Widgets,
    {
        return values;
    } // 返回左值

    DataType data() && // 对于右值Widgets,
    {
        return std::move(values);
    } // 返回右值

private:
    DataType values;
};

int main()
{
    auto vals1 = w.data(); // 调用左值重载版本的Widget::data，
                           // 拷贝构造vals1

    // makeWidget是一个 Widget的工厂方法。
    auto vals2 = makeWidget().data(); // 调用右值重载版本的Widget::data,
                                      // 移动构造vals2
}