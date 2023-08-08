#include <iostream>
#include <condition_variable>
#include <chrono>
using namespace std;
// 以下都是C++17开始的功能：

// 1. 支持初始化语句的if
// if (init; condition) {}

bool foo()
{
    return true;
}
void demo1()
{
    cout << ">> demo1" << endl;
    if (bool b = foo(); b)
    {
        std::cout << std::boolalpha << "good! foo()=" << b << std::endl;
    }
}

// 2. 支持初始化语句的switch

using namespace std::chrono_literals;
std::condition_variable cv;
std::mutex cv_m;
void demo2()
{
    cout << ">> demo2" << endl;
    switch (std::unique_lock<std::mutex> lk(cv_m); cv.wait_for(lk, 100ms))
    {
    case std::cv_status::timeout:
        break;
    case std::cv_status::no_timeout:
        break;
    }
}

// 上面的在if & switch中的初始化会贯穿关键字整个生命周期，所以在{}中可以直接用。
// 目的是减少外部变量的入侵。如果使用了这种方式依然无法避免，拿用不用都一样。
int main()
{
    demo1();
    demo2();
}