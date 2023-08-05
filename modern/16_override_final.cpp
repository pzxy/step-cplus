#include <iostream>
// override 重写，写在派生类方法末尾，表示重写基类方法，如果基类没有则报错。
// final 写在类末尾，或者类方法末尾，表示不能被继承还有重写。目的是为了不改变基类函数行为。
// override final 可以联合使用。
class Base
{
public:
    virtual void log(const char *) const {}
    virtual void foo(int x) {}
};
class BaseWithFileLog : public Base
{
public:
    virtual void log(const char *) const override final {}
};
class Derived : public BaseWithFileLog
{
public:
    void foo(int x){};
};
// 上面代码中基类Base有一个虚函数log，它将日志打印到
// 标准输出。但是为了能更好地保存日志，我们写了一个派生类
// BaseWithFileLog，重写了log函数将日志写入文件中。为了保证
// 重写不会出现错误，并且后来的继承者不要改变日志的行为，为log
// 函数添加了override和final说明符。这样一来，后续的派生类
// Derived只能重写虚函数foo而无法修改日志函数，保证了日志的一
// 致

int main()
{
}