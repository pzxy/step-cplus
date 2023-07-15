#include <iostream>
using namespace std;
void demo1()
{
    cout << "> demo1 long" << endl;
    // 不加L的话，65536可能被编译器认为是int，左移16位，导致溢出。
    long long a = 65536 << 16;
    cout << "a = " << a << endl;
    long long b = 65536L << 16;
    cout << "b = " << b << endl;
}

void demo2()
{
    // c++11统一前缀，utf8是u8，utf16是u，utf32是U
    cout << "> demo2 char" << endl;
    char ufc8c = u8'a';// c++17 才能编译过去。
    // char ufc8c2 = u8'好'; // 编译不过去，因为 好是三个字节。
    char16_t ufc16c = u'好';
    char32_t ufc32c = U'好';
    char ufc8[] = u8"你好世界";
    char16_t ufc16[] = u"你好世界";
    char32_t ufc32[] = U"你好世界";

    wchar_t w = 'a';// c98的 wchar没有规定大小，不同的平台大小不一样，无法适配，因此增加了 char16_t char32_t
}
int main()
{
    demo1();
    demo2();
}