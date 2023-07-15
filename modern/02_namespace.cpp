#include <iostream>
using namespace std;

// 更换新版本时，只需要将新版本的命名空间 inline进来。
namespace Parent
{
    namespace V1
    {
        void foo() { std::cout << "child1 foo" << std::endl; }
    }
    inline namespace V2
    {
        void foo() { std::cout << "child2 foo" << std::endl; }
    }
}

// c++17的命名空间嵌套写法
namespace A::B::C
{
    void foo() { std::cout << "A::B::C" << std::endl; }
}
// 上面相当于下面的写法。
// namespace A
// {
//     namespace B
//     {
//         namespace C
//         {
//             void foo() { std::cout << "A::B::C" << std::endl; }

//         }
//     }
// }

namespace A2::B2::inline C2
{
    void foo() { std::cout << "A2::B2::inline C2" << std::endl; }
}
// 上面相当于下面
// namespace A2::B2
// {
//     inlien namespace C2
//     {
//         void foo() { std::cout << "A2::B2::inline C2" << std::endl; }
//     }
// }

namespace A3::inline B3::C3
{
    void foo() { std::cout << "A3::inline B3::C3" << std::endl; }
}
// 上面相当于下面
// namespace A3
// {
//     inline namespace B
//     {
//         namespace C
//         {
//             void foo() { std::cout << "A3::inline B3::C3" << std::endl; }

//         }
//     }
// }

void demo1()
{
    cout << "> demo1 inline namespace" << endl;
    Parent::V1::foo(); // 如果要用旧版本，就是指定版本号
    Parent::foo();     // 默认每次都是新版本
}

void demo2()
{
    cout << "> demo2 " << endl;
    A::B::C::foo();
    A2::B2::foo();
    A3::C3::foo();
}

int main()
{
    demo1();
    demo2();
}