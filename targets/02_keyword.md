# cpp关键字-类型
# 1)控制流关键字
```cpp
if else switch  while do for continue break return
```

# 2)基本关键字
```cpp
auto bool char double float int long short signed unsigned void
```
此外 < cstdint>中的 uint8_t等也很常用
# 3)复合类型关键字
```cpp
class struct 和 union 等。
```
union 共用体类型

```c++
union one4all
{
    int int_val;
    long long_val;
    double double_val;
}
// 声明赋值
one4all pail;
// 在不同的时间可以存不同类型。但是同时只能存一种。内存大小为最大类型的大小。
pail.int_val = 12;
pail.double_val = 3.445;

// 可以在结构体中这样写
struct widget
{
    int type;
    union id 
    {
        long id_num;
        char id_char[20];
    } id_val;
};
```

# 4)存储类关键字
```cpp
auto register static extern mutable 
```
从 C++ 17 开始，auto 关键字不再是 C++ 存储类说明符，且 register 关键字被弃用
register 存储类用于定义存储在寄存器中而不是 RAM 中的局部变量。这意味着变量的最大尺寸等于寄存器的大小（通常是一个词），且不能对它应用一元的 '&' 运算符（因为它没有内存位置）。
寄存器只用于需要快速访问的变量，比如计数器。还应注意的是，定义 register 并不意味着变量将被存储在寄存器中，它意味着变量可能存储在寄存器中，这取决于硬件和实现的限制。
```C++
{
    register int miles;
}
```
extern 是用来在另一个文件中声明一个全局变量或函数,其实如果我们用class的话，这个关键字就不太需要了。
```c++
// 文件 main.cpp
#include <iostream>
int count ;
extern void write_extern();
int main()
{
   count = 5;
   write_extern();
}

// 文件 support.cpp
#include <iostream>
extern int count;
void write_extern(void)
{
   std::cout << "Count is " << count << std::endl;
}
// 编译
g++ main.cpp support.cpp -o write
// 输出 ./write
Count is 5
```
mutable 说明符仅适用于类的对象，mutable 成员可以通过 const 成员函数修改。

```c++
struct data
{
    char name[30];
    mutable int accesses;
    ...
};
const data veep = {"N",0, ...}
strcpy(veep.name,"Joye Joux");//不允许
veep.accesses++; // 允许
```

# 5)类型修饰关键字
```cpp
const volatile restrict inline friend
```
volatile 修饰的代码,编译器不在进行优化,从而每次都从原来位置来读取这个值.
inline 内联
friend 提供一种方式让别人访问自己私有变量. 基本不用,太离谱.

# 6)异常处理关键字
```cpp
try catch throw
```
# 7)类型转换关键字
```cpp
dynamic_cast reinterpret_cast static_cast const_cast 
```
dynamic_cast 将一个基类指针或引用转换成派生类指针或引用
# 8)其它关键字
```cpp
typedef sizeof operator typename namespace alignof alignas constexpr decltype using nullptr static_assert noexcept sizeof  decltype(auto)
```