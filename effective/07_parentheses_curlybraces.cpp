#include <iostream>
#include <vector>

// 为什么建议使用{}不是()
int main()
{
    // 1. A a(); 可以认为是一个函数，也可以认为是一个类A的初始化。有歧义
    // 2. 花括号优先使用初始化列表，而不是类中显示声明函数。
    std::vector<int> v1{10, 20}; // 两个值 10 ，20
    std::vector<int> v2(10, 20); // 10个值，每个值都是20
    // 3. 花括号它不允许内置类型间隐式的变窄转换，所以花括号更能较少bug
    double x, y, z;
    // int sum1{x + y + z}; // 错误！double的和可能不能表示为int
    int sum2(x + y + z);
    int sum3 = x + y + z;

    // 总结：
    // 使用花括号更符合正常的程序编码思维。优先使用。
}