#include <iostream>
// constexpr对象是const，它被在编译期可知的值初始化
// 当传递编译期可知的值时，constexpr函数可以产出编译期可知的结果
// constexpr对象和函数可以使用的范围比non-constexpr对象和函数要大
// constexpr是对象和函数接口的一部分

// 使用constexpr定义一个常量函数
constexpr int fibonacci(int n)
{
    return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    // 使用常量函数来初始化数组，可以在编译器求值，而不是在运行期间。
    constexpr int fib[] = {fibonacci(0), fibonacci(1), fibonacci(2), fibonacci(3), fibonacci(4)};
    for (int i = 0; i < 5; i++)
    {
        std::cout << fib[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
