#include <iostream>
#include <cstdint>
#include <cassert>
using namespace std;
// static_cast 基本类型的转化 ，int->string等。也可进行父子类转换，但是不检查。并且static_cast是不会报错的。
// dynamic_cast 父子类之间的转换，会检查，如果转换失败返回空。
// reinterpret_cast
// const_cast
// any_cast
/**
std::dec：表示输出整数时使用十进制格式。
std::oct：表示输出整数时使用八进制格式。
std::hex：表示输出整数时使用十六进制格式。
std::showbase：表示在输出整数时显示进制前缀（例如 0x）。
std::showpoint：表示在输出浮点数时显示小数点和末尾的零。
std::setw(n)：表示输出域宽为 n 个字符，不足时在左侧填充空格。
std::setfill(c)：表示在输出域宽不足时使用字符 c 进行填充。
std::left：表示在输出域宽不足时左对齐。
std::right：表示在输出域宽不足时右对齐。
*/
int f()
{
    return 42;
}
/**
    int i = 7;

    // pointer to integer and back
    std::uintptr_t v1 = reinterpret_cast<std::uintptr_t>(&i); // static_cast is an error
    std::cout << "The value of &i is " << std::showbase << std::hex << v1 << '\n';
    int* p1 = reinterpret_cast<int*>(v1);
    assert(p1 == &i);

    // pointer to function to another and back
    void(*fp1)() = reinterpret_cast<void(*)()>(f);
    // fp1(); undefined behavior
    int(*fp2)() = reinterpret_cast<int(*)()>(fp1);
    std::cout << std::dec << fp2() << '\n'; // safe

    // type aliasing through pointer
    char* p2 = reinterpret_cast<char*>(&i);
    std::cout << (p2[0] == '\x7' ? "This system is little-endian\n"
                                 : "This system is big-endian\n");

    // type aliasing through reference
    reinterpret_cast<unsigned int&>(i) = 42;
    std::cout << i << '\n';

    [[maybe_unused]] const int &const_iref = i;
    // int &iref = reinterpret_cast<int&>(
    //     const_iref); // compiler error - can't get rid of const
    // Must use const_cast instead: int &iref = const_cast<int&>(const_iref);
*/

void reinterpret_cast_demo()
{
    cout << "> reinterpret_cast_demo" << endl;
    int i = 7;
    // pointer to integer and back
    std::uintptr_t v1 = reinterpret_cast<std::uintptr_t>(&i); // static_cast is an error
    std::cout << "The value of &i is " << std::showbase << std::hex << v1 << '\n';
    int *p1 = reinterpret_cast<int *>(v1);
    assert(p1 == &i);

    // pointer to function to another and back
    // typedef void (*fptr)(); c中可以这样定义函数指针，然后直接使用fptr就行了。这里的 void表示返回值，()表示入参，(*)表示函数指针，(*fptr)中的fptr可以看成函数指针的变量。
    // fptr fp1 = reinterpret_cast<fptr>(f);
    void (*fp1)() = reinterpret_cast<void (*)()>(f); // 明明f是一个有返回值的函数，重新解析成了一个没有返回值的函数指针。
    // fp1(); undefined behavior
    int (*fp2)() = reinterpret_cast<int (*)()>(fp1); // 将没有返回值的函数值很fp1，重新解析成了一个有返回值的函数指针。
    std::cout << std::dec << fp2() << '\n';          // safe，调用函数后返回。

    // c++中声明函数不使用 typedef，而是using
    using func = int (*)();
    func f2 = f;
    std::cout << f2() << std::endl;

    // type aliasing through pointer
    char *p2 = reinterpret_cast<char *>(&i);
    std::cout << (p2[0] == '\x7' ? "This system is little-endian\n"
                                 : "This system is big-endian\n");

    // type aliasing through reference
    reinterpret_cast<unsigned int &>(i) = 42;
    std::cout << i << '\n';

    [[maybe_unused]] const int &const_iref = i;
    // int &iref = reinterpret_cast<int&>(
    //     const_iref); // compiler error - can't get rid of const
    // Must use const_cast instead: int &iref = const_cast<int&>(const_iref);
}

int main()
{
    reinterpret_cast_demo();
}
