# 面向对象的窍门

# 类如何设计
- 继承不要超过三层。
- 少用内部类，可以提出来。

# 编码准则
1. 多用`final`关键字，禁止别人继承。
```cpp
class DemoClass final    // 禁止任何人继承我
{ ... };


class Interface        // 接口类定义，没有final，可以被继承
{ ... };           

class Implement final : // 实现类，final禁止再被继承
      public Interface    // 只用public继承
{ ... };
```

2. C++ 里类的四大函数：构造函数、析构函数、拷贝构造函数、拷贝赋值函数。C++11 因为引入了右值（Rvalue）和转移（Move），又多出了：转移构造函数和转移赋值函数。现在一个类总是会有六大基本函数：三个构造、两个赋值、一个析构。
- 因此要使用`default`,明确告诉编译器使用默认实现。
```cpp
class DemoClass final 
{
public:
    DemoClass() = default;  // 明确告诉编译器，使用默认实现
   ~DemoClass() = default;  // 明确告诉编译器，使用默认实现
};
```
3. 比如说还可以禁止对象拷贝，就可以用这种语法显式地把拷贝构造和拷贝赋值“delete”掉，让外界无法调用

```cpp
class DemoClass final 
{
public:
    DemoClass(const DemoClass&) = delete;              // 禁止拷贝构造
    DemoClass& operator=(const DemoClass&) = delete;  // 禁止拷贝赋值
};
```
4. 如果你的类里有单参数的构造函数，或者是转型操作符函数，为了防止意外的类型转换，保证安全，就要使用“explicit”将这些函数标记为“显式”。
```cpp
class DemoClass final 
{
public:
// 不加的话，可以写 DemoClass a = "a" ，相当于 DemoClass a("a")，加了的话，只能这样写 DemoClass a("a")
    explicit DemoClass(const string_type& str)  // 显式单参构造函数
    { ... }

    explicit operator bool()                  // 显式转型为bool
    { ... }
};
```

# 常用实用技巧
1. 委托构造
```cpp

class DemoDelegating final
{
private:
    int a;                              // 成员变量
public:
    DemoDelegating(int x) : a(x)        // 基本的构造函数
    {}  

    DemoDelegating() :                 // 无参数的构造函数
        DemoDelegating(0)               // 给出默认值，委托给第一个构造函数
    {}  

    DemoDelegating(const string& s) : // 字符串参数构造函数
        DemoDelegating(stoi(s))        // 转换成整数，再委托给第一个构造函数
    {}  
};
```
2. 成员变量初始化
```cpp

class DemoInit final                  // 有很多成员变量的类
{
private:
    int                 a = 0;        // 整数成员，赋值初始化
    string              s = "hello";  // 字符串成员，赋值初始化
    vector<int>         v{1, 2, 3};   // 容器成员，使用花括号的初始化列表
public:
    DemoInit() = default;             // 默认构造函数
   ~DemoInit() = default;             // 默认析构函数
public:
    DemoInit(int x) : a(x) {}         // 可以单独初始化成员，其他用默认值
};

```
3. 类型别名
```cpp

using uint_t = unsigned int;        // using别名
typedef unsigned int uint_t；      // 等价的typedef

class DemoClass final
{
public:
    using this_type         = DemoClass;          // 给自己也起个别名
    using kafka_conf_type   = KafkaConfig;        // 外部类起别名

public:
    using string_type   = std::string;            // 字符串类型别名
    using uint32_type   = uint32_t;              // 整数类型别名

    using set_type      = std::set<int>;          // 集合类型别名
    using vector_type   = std::vector<std::string>;// 容器类型别名

private:
    string_type     m_name  = "tom";              // 使用类型别名声明变量
    uint32_type     m_age   = 23;                  // 使用类型别名声明变量
    set_type        m_books;                      // 使用类型别名声明变量

private:
    kafka_conf_type m_conf;                       // 使用类型别名声明变量
};
```