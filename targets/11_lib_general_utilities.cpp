#include <iostream>
#include <type_traits>
using namespace std;
void metaprograming_lib()
{
    cout << "metaprograming lib" << endl;
    // type_traits 在编译器断言类型。
    cout << "void: " << is_void<void>::value << endl;
    cout << "void: " << is_void<int>::value << endl;
    // <utility> std::integer_sequence作为函数模版的实参时，可以将行参展开。
}

int main()
{
    metaprograming_lib();
}
