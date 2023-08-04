#include <iostream>
#include <string>
using namespace std;
// 什么是聚合类型？
// 聚合类型是可以用{}来初始化的类型。
// 在C++11之前，只有数组和结构体才是聚合类型。但是在C++11中，还引入了一种新的聚合类型——std::initializer_list
// 因此当我们使用{}来初始化时，编译器回会类型推导看看是不是 std::initializer_list 类型。
// 如果可以解释成这个类型的话，列表初始化时，就会遍历 std::initializer_list 中的数据，赋值给自己。

// C++17对于聚合类型扩展了，这样的话，就算有的类没有写初始化列表，也可以使用{}完成初始化。
// 聚合类型需要满足以下条件：
// 1. 没有用户提供的构造函数。
// 2. 没有私有和受保护的非静态数据成员。
// 3. 没有虚函数。
// C++17后如果存在继承关系的话：
// 4. 必须是公开的基类，不能别私有或者受保护的基类。
// 5. 必须是非虚继承。

// 需要注意的是，只要满足这5个条件，则派生类就是聚合类型。和基类是不是派生类没有关系。

// 1. 例子
class MyString : public std::string
{
    // std:;string 不是聚合类型，因为内部有用户提供的构造函数。
    // MyString是聚合类型，虽然继承了string，但是是公开继承且是非虚继承（非虚继承是指一个派生类继承基类的时候，基类的成员函数不是虚函数。）
    // MyString中不存在用户提供的构造函数，虚函数，私有或受保护的数据成员。
};

void demo1()
{
    cout << "> demo1" << endl;
    // is_aggregate_v 可以判断出来类型是不是聚合类型。
    std::cout << "std::is_aggregate_v<std::string> = "
              << std::is_aggregate_v<std::string> << std::endl;
    std::cout << "std::is_aggregate_v<MyString> = "
              << std::is_aggregate_v<MyString> << std::endl;
}

// 2. 聚合类型的初始化。
class Count
{
public:
    int Get() { return count_++; }
    int count_ = 0;
};
class MyStringWithIndex : public std::string,
                          public Count
{
public:
    int index_ = 0;
};
void demo2()
{
    cout << "> demo2" << endl;
    // 之前初始化基类的时，需要在派生类的构造方法中来初始化，现在可以直接初始化。
    // 按照继承的顺序来初始化。
    MyStringWithIndex s{"hello", 11, 22};
}

// 3. 扩展聚合类型的兼容问题。
class BaseData
{
    int data_;

public:
    int Get() { return data_; }

protected:
    BaseData() : data_(11) {}
};
class DerivedData : public BaseData
{
public:
};

void demo3()
{
    cout << "> demo3" << endl;
    DerivedData d{};
    // g++ --std=c++14 15_aggregate_type.cpp 编译成功
    // g++ --std=c++17 15_aggregate_type.cpp 编译失败
    // g++ --std=c++20 15_aggregate_type.cpp 编译失败
    // 14可以成功，是因为 d{} 是调用的默认构造函数，默认构造函数再调用BaseData的构造函数。
    // 17失败，是因为DerivedData是聚合类型， d{}是聚合类型初始化，因为BaseData中的构造函数是受保护的，所以不能被调用。
}

// 4. 禁止聚合类型使用用户声明的构造函数
int main()
{
    demo1();
    demo2();
    demo3();
}