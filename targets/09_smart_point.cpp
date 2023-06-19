#include <iostream>
#include <memory>

using namespace std;

class Test
{
public:
    Test()
    {
        cout << "Test Constructor" << endl;
    }
    ~Test()
    {
        cout << "Test Destrctor" << endl;
    }
};

// auto_ptr 赋值会移交所有权。使用auto用最新的编译器，如果不加参数的话会编译不过去的。
// void auto_smart_point(){
//     // 智能指针通过new 来创建的话， 就失去了智能指针的本意了。
//     // auto_ptr<Test> p = new auto_ptr<Test>(new Test());
//     auto_ptr<Test> p1(new Test);
//     auto_ptr<Test> p2(new Test);
//     p1 = p2;
//     // auto_ptr智能指针 赋值会转移所有权，此时p2就成了null
//     cout << p1 << endl;
//     cout << p2 << endl;
// }

void unique_smart_point()
{
    unique_ptr<string> p1{new string("i am p1")};
    unique_ptr<string> p2{new string("i am p2")};
    // 不允许左值赋值
    // p1 = p2;
    // unique_ptr<string> p3 = p1; //这是不允许的。
    unique_ptr<string> p3{std::move(p2)};
    cout << p1.get() << endl; // 0x15b606bd0
    cout << p2.get() << endl; // 0
    cout << p3.get() << endl; // 0x15b606bf0

    // 这是不是构造方法，所以不同担心所有权的问题。
    auto p4 = make_unique<string>(*p1);
    // 指针的节本操作，get() 返回指针，release() 返回指针并释放所有权，reset() 释放所有权,或者重新设置新的值。
    p3.release();
    cout << p3.get() << endl;
    cout << p4.get() << endl;
    p4.reset(new string{"reset success"}); // 如果是reset()的话，p4就是空指针了。
    cout << p4.get() << endl;
    p4.reset(); // 如果是reset()的话，p4就是空指针了。
    cout << p4.get() << endl;

    // 指针陷阱
    // unique_ptr<string> p5;
    // string *str = new string("智能指针的内存管理陷阱");
    // p5.reset(str); // p1托管str指针
    // {
    //     unique_ptr<string> p6;
    //     p6.reset(str); // p2接管str指针时，会先取消p1的托管，然后再对str的托管
    // }

    // // 此时p1已经没有托管内容指针了，为NULL，在使用它就会内存报错！
    // // 不过呢，我发现，新的编译器是能检查出来这个问题的。所以不用太担心这个。
    // cout << "str: " << *p5 << endl;
}

// shard_ptr通过引用计数来做到的。
void shared_smart_point()
{
    cout << "shared_smart_point()" << endl;
    shared_ptr<int> p1{new int(1)};
    shared_ptr<int> p2 = p1;
    shared_ptr<int> p3 = make_shared<int>(3);
    cout << "p1: " << *p1.get() << endl;
    cout << "p2: " << *p2.get() << endl;
    cout << "p3: " << *p3.get() << endl;

    // 释放对象
    // p1 = nullptr;
    // p1 = NULL;

    // 重置和交换
    p2.swap(p3);
    p2.reset(new int(2));

    cout << "p1: " << p1.get() << endl;
    cout << "p2: " << p2.get() << endl;
    cout << "p3: " << *p3.get() << endl;
}

// 多个引用只会计数一次。从shared_ptr创建，或者说托管原来的指针。
// 没有release();
void weak_smart_point()
{
    cout << "weak_smart_point()" << endl;
    auto sp = std::make_shared<int>(42);
    weak_ptr<int> p1{sp};
    weak_ptr<int> p2;
    p2 = p1;
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;

    // 不能使用 * 或者 ->,所以也没有 get(); 因此不能使用 p1.get();
    // 使用的时候要转换成共享指针。
    shared_ptr<int> sp2 = p1.lock();
    sp2.get();
    // weak是对shared指针的降级，托管。
    // expired()查看托管的指针是够有效。托管对象的所有对象都被销毁后，则过期。
    sp = nullptr;
    sp2 = nullptr;
    if (p1.expired())
    {
        cout << "is expired" << endl;
    }
}

int main()
{
    unique_smart_point();
    shared_smart_point();
    weak_smart_point();
    // 指针的一些常见问题:
    // 1. 循环引用。
    // 2. 一定要使用。release()的返回值。
    // 3. 不要将同一个对象交给多个智能指针来管理。
    // 4. 不要使用get()去初始化另外一个指针。
}
