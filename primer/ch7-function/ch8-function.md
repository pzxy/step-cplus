# inline
内联可以减少函数的调用，在go中都是编译器自己判断将一些小块代码进行内联的。
在类定义中的定义的函数都是内联函数，即使没有使用 inline 说明符。

```C++
inline double square(double x){return x*x}
```

# 引用变量
引用是一个别名，不能无中生有，指针是一个类型。引用相当于rust中的借用，只不过借用只能读，但是我们可以使用`const`来修饰引用达到只读的效果。而引用基本上和指针有同样的功能。
```c++
int rats = 101;
// 声明引用的时候必须被赋值。
int & rodents = rats;
int * pt = &rats;

// 引用作为参数
void swapr(int & a,int & b);// a,b可以直接用
void swapr(int * p,int & q);// p,q需要使用解引用运算符号 * 
```

# 函数重载
在同一个作用域内声明几个功能类似的同名函数，但是签名不一样。
```c++
class printData
{
   public:
      void print(int i) {
        cout << "整数为: " << i << endl;
      }
      void print(double  f) {
        cout << "浮点数为: " << f << endl;
      }
      void print(char c[]) {
        cout << "字符串为: " << c << endl;
      }
};
```

# 函数模板
就是泛型，在rust中是直接在方法或者trait名字后面通过<>来声明的。
```c++
// 模板的主要作用是告诉编译器后面的T是模板而不是一个具体类型。
// c++98中可以这样写 template <class T>
template <typename T>
void Swap(T &a,T &b)
```

