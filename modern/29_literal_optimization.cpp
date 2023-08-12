#include <iostream>
using namespace std;
// 这部分列举几个常用的。其他的用到了再看。
// 1. 十六进制浮点数字面量。
// c++17 打印浮点数
void demo1()
{
    cout << ">> demo" << endl;
    double float_array[]{0x1.7p+2, 0x1.f4p+9, 0x1.df3b64p-4};
    for (auto elem : float_array)
    {
        std::cout << std::hexfloat << elem
                  << " = " << std::defaultfloat << elem << std::endl;
    }
}

// 2. 二进制整数字面量
// c++14 引入
// 十六进制 0x
// 八进制 0
// 二进制 0b

// 3. 单引号作为整数分隔符，c++14
// constexpr int x = 123'456;
// static_assert(x == 0x1e'240);
// static_assert(x == 036'11'00);
// static_assert(x == 0b11'110'001'001'000'000);

// 4. 原生字符字面量
// R("")

// 5. 用户自定义字面量，用到的时候再看。

void demo2()
{
    cout << ">> demo" << endl;
    auto x = 0b11001101L + 0xcdl + 077LL + 42;
    std::cout << "x = " << x << ", sizeof(x) = " << sizeof(x) << std::endl;
}
int main()
{
    demo1();
    demo2();
}
