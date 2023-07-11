#include <iostream>
using namespace std;
// https://en.cppreference.com/w/cpp/language/rule_of_three
// 1. 一个类如果什么都不写,所有构造都会生成。
class A
{
};
void demo1()
{
    cout << "> demo1" << endl;
    A a{};
    A b = a;
    A c{a};
    A d{std::move(a)};
};

int main()
{
    demo1();
}