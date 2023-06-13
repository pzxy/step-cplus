#include <iostream>
#include <array>
#include <tuple>
#include <map>

using namespace std;

int main()
{
    // auto 是声明常量值
    // auto & 是声明左值引用。
    // auto && 是声明右值引用。
    // c++ 14开始增加了 decltype 关键字，可以使用 decltype(auto) 来声明变量，自动符合上面的三种情况。

    decltype(auto) a = 1;
    // 2. 类模板的模板参数推导
    pair<int, int> p(1, 2);
    // 常用
    auto p2 = make_pair(1, 2);
    // c++17
    pair p3{1, 2};

    int a1[] = {1, 2, 3};
    array<int, 3> a2{1, 2, 3}; // 啰嗦
    // array<int> a3{1, 2, 3}; 不行
    // c++17
    array a4{1, 2, 3};

    // 3. 结构化绑定
    multimap<string, int> mmp{
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4}};
    multimap<string, int>::iterator lower, upper;
    std::tie(lower, upper) =
        mmp.equal_range("four");
    // c++17

    auto [lower2, upper2] =
        mmp.equal_range("four");
    // 4. 列表初始化

    vector<int> v{1, 2, 3, 4, 5};
    // 5. 统一初始化，尽量使用{}来初始化，不使用()，因为()有二义性。编译器可能认为你在声明一个函数，而不是一个对象。

    // 6. 初始化表达式
    // class Complex
    // {
    // public:
    //     Complex() {}
    //     Complex(float re) : re_(re) {}
    //     Complex(float re, float im)
    //         : re_(re), im_(im) {}

    // private:
    //     float re_{0};
    //     float im_{0};
    // };
}