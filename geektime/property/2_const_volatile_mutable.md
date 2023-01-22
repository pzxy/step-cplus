# const
限定只读
```cpp
int x = 100;
const int& rx = x;
const int* px = &x;
string name = "uncharted";
const string* ps1 = &name; // 指向常量
*ps1 = "spiderman";        // 错误，不允许修改

// 限定成员函数只读
class DemoClass final
{
private:
    const long  MAX_SIZE = 256;    // const成员变量
    int         m_value;           // 成员变量
public:
    int get_value() const        // const成员函数
    {
        return m_value;
    }
};
```

# volatile
volatile含义是“不稳定的”“易变的”，在 C++ 里，表示变量的值可能会以“难以察觉”的方式被修改（比如操作系统信号、外界其他的代码），所以要禁止编译器做任何形式的优化，每次使用的时候都必须“老老实实”地去取值。

单纯的const限定，其实编译器会优化，在代码中使用这个值的地方，会用这个值替换掉。而用了volatile限定以后，则不会进行优化了，而是调用的时候，去原来的地方取值。
```cpp

// 需要加上volatile修饰，运行时才能看到效果
const volatile int MAX_LEN  = 1024;

auto ptr = (int*)(&MAX_LEN);
*ptr = 2048;
cout << MAX_LEN << endl;      // 输出2048
```

# mutable
mutable 与 volatile 的字面含义有点像，但用法、效果却大相径庭。volatile 可以用来修饰任何变量，而 mutable 却只能修饰类里面的成员变量，表示变量即使是在 const 对象里，也是可以修改的。

```cpp
class DemoClass final
{
private:
    mutable mutex_type  m_mutex;    // mutable成员变量
public:
    void save_data() const          // const成员函数
    {
        // do someting with m_mutex
    }
};
```