#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 1. 联合类型在c++中的局限性
union U
{
    int x1;
    float x2;
    // c++规定 联合类型的成员变量的类型不能是一个非平凡类型，也就是说他的成员类型不能有自定义的构造函数
    // 下面会编译失败。因为std::string x3有自定义的构造函数。
    string x3;
    // 但是加上构造函数和析构函数就可以了。
    U() {}  // 存在非平凡类型成员，必须提供构造函数
    ~U() {} // 存在非平凡类型成员，必须提供析构函数
};

void demo1()
{
    cout << "> demo1" << endl;
    U u;
    // 修改一个，另外一个也会改变，因为是共享内存。
    u.x1 = 5;
    std::cout << u.x1 << std::endl;
    std::cout << u.x2 << std::endl;
    u.x2 = 5.0;
    std::cout << u.x1 << std::endl;
    std::cout << u.x2 << std::endl;
}

// 2. 使用非受限联合类型
union U2
{
    U2() {}  // 存在非平凡类型成员，必须提供构造函数
    ~U2() {} // 存在非平凡类型成员，必须提供析构函数

    int x1;
    float x2;
    std::string x3;
    std::vector<int> x4;

    // 注意：这种写法是不行的，因为不知道当前激活的是哪个成员，所以无法自己调用成员的析构函数。
    // U2() : x3() {}
    // ~U() { x3.~basic_string(); }
};

void demo2()
{
    cout << "demo2" << endl;
    U2 u;
    // 非平凡类型x3并没有被构造 ,赋值的时候会出错。
    // u.x3 = "hello world";

    // 解决方法，使用 placement new的技巧来初始化构造x3
    new (&u.x3) std::string("hello world");
    std::cout << u.x3 << std::endl;
    u.x3.~basic_string();
}

int main()
{
    demo1();
    demo2();
    // 总结：
    // Union基本很少用到，除非特别关心内存。
    // C++17以后用std::variant来代替联合体。
}
