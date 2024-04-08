#include <iostream>

using namespace std;
// 尽量使用nullptr而不是0和NULL
void f(int); // 三个f的重载函数
void f(bool);
void f(void *);

int f1(std::shared_ptr<Widget> spw);    // 只能被合适的
double f2(std::unique_ptr<Widget> upw); // 已锁互斥量
bool f3(Widget *pw);                    // 调用

int main()
{
    // NULL和0都不是指针类型。
    // NULL没有一个确定的类型。可以是long类型。

    // 1. 歧义
    f(0); // 调用f(int)而不是f(void*)

    f(NULL); // 可能不会被编译，一般来说调用f(int)，如果NULL是long类型会自动转成int类型，并且从long转到int和从0L转到*void都认为正常的。 有歧义
    // 绝对不会调用f(void*)
    f(nullptr); // 调用重载函数f的f(void*)版本，没有歧义

    // 2. 歧义2
    auto result = findRecord(/* arguments */);
    // 有歧义，无法判断result是指针还是整型，因为0L可以转成*void
    if (result == 0)
    {
    }
    // 使用 nullptr没有歧义，一定是指针类型。
    if (result == nullptr)
    {
    }
    // 3. 歧义3 ，下面的代码之所以能编译通过，f3调用可以理解，f2调用也可以理解，f1是因为将0当成了NULL
    // 之所以会这样，因为NULL是一个宏，它定义的值就是0L 也就是long类型。
    std::mutex f1m, f2m, f3m; // 用于f1，f2，f3函数的互斥量

    using MuxGuard = // C++11的typedef，参见Item9
        std::lock_guard<std::mutex>;

    {
        MuxGuard g(f1m);     // 为f1m上锁
        auto result = f1(0); // 向f1传递0作为空指针
    }                        // 解锁
    {
        MuxGuard g(f2m);        // 为f2m上锁
        auto result = f2(NULL); // 向f2传递NULL作为空指针
    }                           // 解锁
    {
        MuxGuard g(f3m);           // 为f3m上锁
        auto result = f3(nullptr); // 向f3传递nullptr作为空指针
    }

    // 总结
    // 必须使用nullptr，而不是NULL，因为NULL的宏定义是0L，也就是long类型。
    // 因此当编译的时候0和NULL是很难区分的，特别是重载 f(int) 和 f(NULL) 的时候。
    // 你希望调用的是NULL的重载，但实际上可能调用的是int的重载。
    // 但是使用nullptr就没有这个问题，nullptr是单独的一个类型，编译器固定认为nullptr就是指针类型。
}

