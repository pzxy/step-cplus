#include <iostream>
#include <string>
#include <thread>
#include <mutex>
using namespace std;
// 1. 线程局部存储，就是说对象内存在线程开始后分配，线程结束时回收且每个线程有对象自己的实例。
// 线程局部存储的对象都独立于各个线程上。要做到这样，需要调用操作系统提供的接口。
// 自己的理解： 线程依赖的数据，都会在线程栈上，而不会在堆上或者其他栈上。

// 2. thread_local
// 用来指定一个变量是线程中的全局变量。
// 可以与 static extern相互结合。
// 作用：可以解决全局变量和静态变量在多线程操作中存在的问题。
// 思考：java中也有这个。go中没有线程的概念，只有协程，

// 注意：thread_local声明的变量只有在运行的时候才能创建。
// thread_local int tv;
// static int sv;
// int main()
// {
//     constexpr int *sp = &sv; // 编译成功，sv的地址在编译时确定
//     constexpr int *tp = &tv; // 编译失败，tv的地址在运行时确定
// }


// 可以看到相同线程中的foo方法，调用了多次，但是只调用了一次RefCount的构造方法。
// 并且该线程内的foo方法，都操作的这个对象。也就是他成了一个该线程内的全局对象。
// 如果没有thread_local的话要实现，需要在多个foo方法外面再套一层，然后创建一个对像传进去。
// 这样很不方便，别人要用这个方法，还需要自己创建对象。
// 实际运用：error打印的时候，我们只管使用log.error来打印，每个线程都会创建自己的全局变量，相同线程的日志都打印到了一个error对象中了。
// 思考：如果是go呢？go没办法做到，只能手动控制创建。
std::mutex g_out_lock;
struct RefCount
{
    RefCount(const char *f) : i(0), func(f)
    {
        std::lock_guard<std::mutex> lock(g_out_lock);
        std::cout << std::this_thread::get_id()
                  << "|" << func
                  << " : ctor i(" << i << ")" << std::endl;
    }
    ~RefCount()
    {
        std::lock_guard<std::mutex> lock(g_out_lock);
        std::cout << std::this_thread::get_id()
                  << "|" << func
                  << " : dtor i(" << i << ")" << std::endl;
    }
    void inc()
    {
        std::lock_guard<std::mutex> lock(g_out_lock);
        std::cout << std::this_thread::get_id()
                  << "|" << func
                  << " : ref count add 1 to i(" << i << ")" << std::endl;
        i++;
    }
    int i;
    std::string func;
};
void foo(const char *f)
{
    std::string func(f);
    thread_local RefCount tv(func.append("#foo").c_str());
    tv.inc();
}
void bar(const char *f)
{
    std::string func(f);
    thread_local RefCount tv(func.append("#bar").c_str());
    tv.inc();
}
void threadfunc1()
{
    const char *func = "threadfunc1";
    foo(func);
    foo(func);
    foo(func);
}
void threadfunc2()
{
    const char *func = "threadfunc2";
    foo(func);
    foo(func);
    foo(func);
}
void threadfunc3()
{
    const char *func = "threadfunc3";
    foo(func);
    bar(func);
    bar(func);
}
void demo2()
{
    cout << "<< demo2" << endl;
    std::thread t1(threadfunc1);
    std::thread t2(threadfunc2);
    std::thread t3(threadfunc3);
    t1.join();
    t2.join();
    t3.join();
}

int main()
{
    demo2();
}
