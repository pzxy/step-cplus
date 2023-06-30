
#include <chrono>
#include <complex>
#include <iostream>
#include <string>
#include <thread>
#include <bitset>

using namespace std;

int main()
{ // 1. 自定义字面量，C++11 引入了自定义字面量，可以使用 operator"" 后缀 来将用户提供的字面量转换成实际的类型。
    // "hello"，字符串字面量，类型是 const char[6]
    // 1，整数字面量，类型是 int
    // 0.0，浮点数字面量，类型是 double
    // 3.14f，浮点数字面量，类型是 float
    // 123456789ul，无符号长整数字面量，类型是 unsigned long
    cout << "i * i = " << 1i * 1i
         << endl;
    cout << "Waiting for 500ms"
         << endl;
    this_thread::sleep_for(500ms);
    cout << "Hello world"s.substr(0, 5)
         << endl;
    // 2. 二进制字面量
    unsigned mask = 0b111000000;
    //  I/O streams 里只有 dec、hex、oct 三个操纵器（manipulator），而没有 bin，因而输出一个二进制数不能像十进制、十六进制、八进制那么直接。一个间接方式是使用 bitset，但调用者需要手工指定二进制位数：
    cout << bitset<9>(mask) << endl;
    // 3. 静态断言
    static_assert(true, "编译期条件表达式,而不是通常的，在运行时再报错。");
    
}