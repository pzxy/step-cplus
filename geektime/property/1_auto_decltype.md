# auto 
表达式的类型推导，但是无法推导声明。
```cpp
auto x = 0L;    // 自动推导为long
auto y = &x;    // 自动推导为long*
auto z {&x};    // 自动推导为long* 

auto err;       // 错误，没有赋值表达式，不知道是什么类型

class X final
{
    auto a = 10;  // 错误，类里不能使用auto推导类型
};
```

auto 总是推导出“值类型”，绝不会是“引用”；
auto 可以附加上 const、volatile、*、& 这样的类型修饰符，得到新的类型。
```cpp
auto        x = 10L;    // auto推导为long，x是long
auto&       x1 = x;     // auto推导为long，x1是long&
auto*       x2 = &x;    // auto推导为long，x2是long*
const auto& x3 = x;     // auto推导为long，x3是const long&
auto        x4 = &x3;   // auto推导为const long*，x4是const long*
```
常用用法,遍历，c++14推导函数返回值
```cpp
vector<int> v = {2,3,5,7,11};  // vector顺序容器

for(const auto& i : v) {      // 常引用方式访问元素，避免拷贝代价
    cout << i << ",";          // 常引用不会改变元素的值
}

for(auto& i : v) {          // 引用方式访问元素
    i++;                      // 可以改变元素的值
    cout << i << ",";
}

auto get_a_set()              // auto作为函数返回值的占位符
{
    std::set<int> s = {1,2,3};
    return s;
}
```
泛型化
```cpp

auto f = [](const auto& x)        // 参数使用auto声明，泛型化
{
    return x + x;
};

cout << f(3) << endl;             // 参数类型是int
cout << f(0.618) << endl;         // 参数类型是double

string str = "matrix";
cout << f(str) << endl;          // 参数类型是string
```

# decltype
decltype获取变量的类型，不仅能够推导出值类型，还能够推导出引用类型，也就是表达式的“原始类型。

```cpp
int x = 0;            // 整型变量

decltype(auto)     x1 = (x);  // 推导为int&，因为(expr)是引用类型
decltype(auto)     x2 = &x;   // 推导为int*
decltype(auto)     x3 = x1;   // 推导为int&
```
decltype它是 auto 的高级形式，更侧重于编译阶段的类型计算，所以常用在泛型编程里，获取各种类型，配合 typedef 或者 using 会更加方便。当你感觉“这里我需要一个特殊类型”的时候，选它就对了。
```cpp

// UNIX信号函数的原型，看着就让人晕，你能手写出函数指针吗？
void (*signal(int signo, void (*func)(int)))(int)

// 使用decltype可以轻松得到函数指针类型
using sig_func_ptr_t = decltype(&signal) ;

// 在定义类的时候，因为 auto 被禁用了，所以这也是 decltype 可以“显身手”的地方。
// 它可以搭配别名任意定义类型，再应用到成员变量、成员函数上，变通地实现 auto 的功能。
class DemoClass final
{
public:
    using set_type      = std::set<int>;  // 集合类型别名
private:
    set_type      m_set;                   // 使用别名定义成员变量

    // 使用decltype计算表达式的类型，定义别名
    using iter_type = decltype(m_set.begin());

    iter_type     m_pos;                   // 类型别名定义成员变量
};
```