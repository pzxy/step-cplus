#include <iostream>
#include <vector>
using namespace std;
// static_cast 基本类型的转化 ，int->string等。也可进行父子类转换，但是不检查。并且static_cast是不会报错的。
// dynamic_cast 父子类之间的转换，会检查，如果转换失败返回空。
// reinterpret_cast
// const_cast
// any_cast
struct B
{
    int m = 42;
    const char *hello() const
    {
        return "Hello world, this is B!\n";
    }
};

struct D : B
{
    const char *hello() const
    {
        return "Hello world, this is D!\n";
    }
};

enum class E
{
    ONE = 1,
    TWO,
    THREE
};
enum EU
{
    ONE = 1,
    TWO,
    THREE
};

void static_cast_demo()
{
    cout << "> static cast demo" << endl;
    // 1. static downcast
    D d;
    B &br = d;
    cout << "1) " << br.hello();
    D &d2 = static_cast<D &>(br);
    cout << "1) " << d2.hello();

    // 2. lvalue to xvalue
    vector<int> v0{1, 2, 3};
    // 下面这两行含义是一样的。
    // vector<int> v2 = static_cast<vector<int>>(std::move(v0));
    vector<int> v2 = static_cast<vector<int> &&>(v0);
    cout << "2) after movem v0.size() = " << v0.size() << endl;

    // 3. initializing conversion
    int n = static_cast<int>(3.14);
    cout << "3) n = " << n << endl;
    vector<int> v = static_cast<vector<int>>(10); // 这个感觉不常用
    cout << "3) v.size() = " << v.size() << endl;

    // 4. discarded-valued expression 弃值表达式。
    static_cast<void>(v2.size()); // c++中警告级别高时，如果某个值没地方使用，会警告，可以使用这个代码。这个代码本身是意义都没有的。

    // 5. inverse of implicit conversion
    void *nv = &n;
    int *ni = static_cast<int *>(nv); // void类型的指针，转成其他指针类型。
    cout << "5) *ni = " << *ni << endl;

    // 6. array-to-point followed by upcast
    D a[10];
    [[maybe_unused]] B *dp = static_cast<B *>(a);

    // 7. scoped enum to int
    E e = E::TWO;
    int two = static_cast<int>(e);
    cout << "7) " << two << endl;

    // 8. int to enum,enum to another enum
    E e2 = static_cast<E>(two);
    EU eu = static_cast<EU>(e2);

    // 9. pointer to member upcast
    int D::*pm = &D::m; // 这里跳过，看不懂
    std::cout << "9) " << br.*static_cast<int B::*>(pm) << endl;

    // 10.  void* to any type
    void *voidp = &e;
    [[maybe_unused]] vector<int> *p = static_cast<vector<int> *>(voidp);

    // 总结常用：
    // 1. 将指针转换成各种类型。
    // 2. 各种基本类型的转换。
    // 3. 不会报错
    // 4. 父子类相互转换，但是不检查是否可以转换，性能高。如果确实无误的话，可以使用。

    // 11. 测试一下 string to int，这是错误的。
    char s = 'ab';
    int i = static_cast<int>(s);
    cout << "11) " << i << endl; // 这里是 98，也就是b生效了，最后面。
    // ------static_cast常用来进行基本类型直接的转换，如char与int、int与float、enum与int之间；
    // ------static_cast也可以转换用户自定义类型，但目标类型必须含有相应的构造函数；
    // ------static_cast还可以转换对象的指针类型，但它不进行运行时类型检查，所以是不安全的；
    // ------static_cast甚至可以把任何表达式都转换成void类型；
    // ------satic_cast不能移除变量的const属性，请参考const_cast操作符；
    // ------static_cast进行的是简单粗暴的转换，所以其正确性完全由程序员自己保证。
}
int main()
{
    static_cast_demo();
}