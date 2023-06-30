#include <iostream>
using namespace std;
struct type
{
    int i;

    type() : i(3) {}

    void f(int v) const
    {
        // this->i = v;                     // compile error: this is a pointer to const
        const_cast<type *>(this)->i = v; // OK as long as the type object isn't const
    }
};
/**
     int i = 3;                 // i is not declared const
    const int& rci = i;
    const_cast<int&>(rci) = 4; // OK: modifies i
    std::cout << "i = " << i << '\n';

    type t; // if this was const type t, then t.f(4) would be undefined behavior
    t.f(4);
    std::cout << "type::i = " << t.i << '\n';

    const int j = 3; // j is declared const
    [[maybe_unused]]
    int* pj = const_cast<int*>(&j);
    // *pj = 4;      // undefined behavior

    [[maybe_unused]]
    void (type::* pmf)(int) const = &type::f; // pointer to member function
    // const_cast<void(type::*)(int)>(pmf);   // compile error: const_cast does
                                              // not work on function pointers
*/
void const_cast_demo()
{
    cout << "> const_cast_demo" << endl;
    int i = 3;
    const int &rci = i;
    // 直接修改
    const_cast<int &>(rci) = 4;
    cout << "i = " << i << endl;

    type t;
    t.f(4);
    cout << "type::i = " << t.i << endl;

    const int j = 3;
    [[maybe_unused]] int *pj = const_cast<int *>(&j);
    *pj = 4;
    cout << "type::pj = " << *pj << endl;
     
    [[maybe_unused]] void (type::*pmf)(int) const = &type::f;// 函数指针是不能去掉const的
    // const_cast<void (type::*)(int)>(pmf);

    // 总结：
    // 将一个变量的const修饰去掉，获取到一个指向他的非const指针，通过这个指针来修改值。
    
}

int main()
{
    const_cast_demo();
}