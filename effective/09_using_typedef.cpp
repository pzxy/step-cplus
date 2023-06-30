#include <iostream>

// 使用 using(c++11)， 而不是typedef(c++98)
int main()
{
    // 1. 使用语法区别
    // FP是一个指向函数的指针的同义词，它指向的函数带有
    // int和const std::string&形参，不返回任何东西
    typedef void (*FP)(int, const std::string &); // typedef

    // 含义同上
    using FP = void (*)(int, const std::string &); // 别名声明
}
// 2. using 可以被模版化，typedef不能

template <typename T>                         // MyAllocList<T>是
using MyAllocList = std::list<T, MyAlloc<T>>; // std::list<T, MyAlloc<T>>
                                              // 的同义词
// MyAllocList<Widget> lw; // 用户代码

// 2.2 如果一定要使用 typedef，只能定义到 struct 中，也就是最原始的办法
template <typename T> // MyAllocList<T>是
struct MyAllocList
{                                          // std::list<T, MyAlloc<T>>
    typedef std::list<T, MyAlloc<T>> type; // 的同义词
};

MyAllocList<Widget>::type lw; // 用户代码

// 2.3 如果要在一个模版类中使用 另外一个一个使用了typedef模版定义的对象，很复杂，必须在前面加上 typename
template <typename T>
class Widget
{                                       // Widget<T>含有一个
private:                                // MyAllocLIst<T>对象
    typename MyAllocList<T>::type list; // 作为数据成员
};

// 2.4 如果是 using 实现的模版类，在别的模版类中要使用，则很方便。
template <typename T>
using MyAllocList = std::list<T, MyAlloc<T>>; // 同之前一样

template <typename T>
class Widget
{
private:
    MyAllocList<T> list; // 没有“typename”，没有“::type”
};

// 2.5 在2.3中为什么要加上 typename呢？这是因为编译器不确定 MyAllocList<T>::type 是一个类型。因为可能存在一个MyAllocList的它们没见到的特化版本，那个版本的MyAllocList<T>::type指代了一种不是类型的东西
// 那么在2.4中编译器可以直接确定这是一个类型。当编译器处理Widget模板时遇到MyAllocList<T>（使用模板别名声明的版本），它们知道MyAllocList<T>是一个类型名，因为MyAllocList是一个别名模板：它一定是一个类型名。因此MyAllocList<T>就是一个非依赖类型（non-dependent type），就不需要也不允许使用typename修饰符。
// 看下面的例子： MyAllocList<Wine>::type不是一个类型。如果Widget使用Wine实例化，在Widget模板中的MyAllocList<Wine>::type将会是一个数据成员，不是一个类型。
// 在Widget模板内，MyAllocList<T>::type是否表示一个类型取决于T是什么，这就是为什么编译器会坚持要求你在前面加上typename
class Wine
{
    …
};

template <> // 当T是Wine
class MyAllocList<Wine>
{ // 特化MyAllocList
private:
    enum class WineType // 参见Item10了解
    {
        White,
        Red,
        Rose
    }; //"enum class"

    WineType type; // 在这个类中，type是
    …              //一个数据成员！
};

// 3. 元编程，也是上面2中的问题，使用typename需要加::type
// 使用using，可以转化成c++14中的样子来用。就不需要type了。
// todo 这里理解的不深，以后再理解。
template <class T>
using remove_const_t = typename remove_const<T>::type;

template <class T>
using remove_reference_t = typename remove_reference<T>::type;

template <class T>
using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

// 总结：
// typedef不支持模板化，但是别名声明支持。
// 别名模板避免了使用“::type”后缀，而且在模板中使用typedef还需要在前面加上typename
// C++14提供了C++11所有type traits转换的别名声明版本