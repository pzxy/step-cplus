[assert](#assert) [const](#const) [static](#static) 
# assert

```cpp
#include <stdio.h> 
// assert在这头文件中, 
// 可以在引入这个文件前,通过 #define NDEBUG 禁用断言宏
// #define NDEBUG
#include <assert.h> 

int main() 
{ 
    int x = 7; 
    x = 9; 
    // 必须x等于7,否则报错,这是一种正向判断,也就是必须这样.否则报错.
    assert(x==7); 
    return 0; 
} 
```
# const
const常量具有类型，编译器可以进行安全检查；#define宏定义没有数据类型，只是简单的字符串替换，不能进行安全检查
const常量支持所有类型
其他情况下它只是一个 const 限定的变量，不要将与常量混

```bash
const char * a; //指向const对象的指针或者说指向常量的指针。
char const * a; //同上
char * const a; //指向类型对象的const指针。或者说常指针、const指针。
const char * const a; //指向const对象的const指针。
```
这里其实很好理解,将`const char` 看成一个类型,`*a`是一个指向`const char`类型的指针. 因为这个对象类型是常量类型,所以不能边.
而 `* const a` 就是用`const`修饰`*a`的固定写法. 见到这种,就认为这个指针本身不可变就行了.

其实只需要记住 `* const` 这种情况,也就是当const在`*`右边:说明这个指针不能被改变.别的情况都不用记的.

指针换成引用也是一样的道理.

常用例子:
```cpp
int func(const class & a){};
int getField() const {} // 相当于 getField(const A * const this)
```

# static

`static`修饰的东西是全局的. 只能存在一个,且有特殊内存空间.


- `static` 变量的生命周期与程序的生命周期相同，即在程序运行期间一直存在，而不是在函数调用结束后就被销毁。
- `static` 函数的作用域仅限于定义该函数的文件，即只能在该文件中被调用。
- `static` 类成员属于整个类，而不是某个对象，因此所有对象共享同一个静态成员。
- `static` 成员函数不属于任何类对象或类实例

常用例子:

```cpp
// 单例
class demo {
public:
    static demo & instance();
};

demo & demo::instance() {
    static demo ins;
    return ins;
}
// 需要多个模块共享访问时,也可以使用 static
// 一些小功能,适当使用static,会很方便
```
# this
成员函数的默认参数,相当于rust中的self.
# inline
内联,将一些简短的方法,代码贴到别的函数中,这样可以减少一次函数调用.

内联是可以修饰虚函数的，但是当虚函数表现多态性的时候不能内联.因为内联要在编译期,确定代码片段.
常用例子
```cpp
inline void A::f1(int x){

}
```
# sizeof
计算类型大小
- 类的大小根据成员变量决定,具体是对齐以后的大小.
- 派生类的大小是基类+派生累的所有成员的大小.
- 虚函数无论多少个,都是8个字节大小.
```cpp
class A{};
sizeof(A);
```
# 函数指针
可以声明函数指针变量和函数指针类型
```cpp
// 1. FuncPtr 是一种类型,这种方式很通用.方便.
typedef void (*FuncPtr)(void);

void func() { 
    cout << "This is a function." << endl;
}

int main() {
    FuncPtr fp = &func; 
    fp(); 
    return 0;
}
// 2. 如果只是简单使用,直接创建一个函数指针变量用
void func() { 
    cout << "This is a function." << endl;
}

int main() {
    void (*fp)(void) = &func;
    fp(); 
    return 0;
}
```
# 虚函数
- 使用`virtual`修饰的函数是虚函数.如果 ` virtual void func() = 0`,则这个函数是纯虚函数.
- 只有使用`virtual`修饰的函数,派生类才能使用`override`重写函数,当然也可以选择不覆盖. 如果要覆盖的话,`virtual`和`override`要成对出现.
```cpp
class Base {
public:
    virtual void func() = 0; // 纯虚函数
};

class Derived : public Base {
public:
    void func() override { // 使用 override 修饰符
        // 实现函数体
    }
};
```

# 虚表
[https://github.com/pzxy/CPlusPlusThings/tree/master/basic_content/vptr_vtable](https://github.com/pzxy/CPlusPlusThings/tree/master/basic_content/vptr_vtable)
![vtable.jpg](./vtable.jpg)
虚表是一种用于动态绑定的方式.
rust中通过这种办法,来抹除trait对象的类型.称为动态分发

# virtual
- 构造函数不能用 `virtual` 修饰,因为虚表中的`vptr`需要再构造期间创建,这段代码是编译器加上去的,如果构造函数是虚函数,则不能创建`vptr`了.
- 析构函数可以用 `virtual` 修饰.并且如果这个类本省就是为了让别的类继承,那么析构函数就应该使用 `virtual` 修饰.
- 还有一些偏门的例子,就认为错的就行了,只关注正确的就行了.

正常例子:
```cpp
// 作为基类
class Base {
public:
    Base();
    virtual ~Base();
    virtual void func() = 0; // 纯虚函数
};
```

# dynamic_cast
多态类型间进行转换,相比`C`风格的强制类型转换和`C++ `, `reinterpret_cast`，`dynamic_cast`提供了类型安全检查.


# volatile  
- `volatile` 修饰的变量,编译器不会去优化.
- `volatile` 修饰的变量,每次都会去内存中读取,而不是读寄存器中的值.

```cpp
// 1. 编译器进行优化
int  *output = (unsigned  int *)0xff800000; //定义一个IO端口；  
int  init(void)  {  
    int i;  
    for(i=0;i< 10;i++)
    {  
    *output = i;  
    }  
}
// 优化成了这个
int  init(void)  
{  
    *output = 9;  
}
// 2. 必须从内存中读取
int square(volatile int *ptr) { 
    int a,b; 
    // 第一次从内存中读取 ptr
    a = *ptr; 
    // 第二次从内存中读取 ptr,ptr的值可能已经被别处代码改掉了.
    b = *ptr; 
    return a * b; 
}
// 所以可以改成这样,或者去掉 volatile 也可以.
int square(volatile int *ptr) { 
    int a;
    a = *ptr; 
    return a * a; 
}
```

# union & bit field
union是一种特殊的类,里面的变量公用一个空间,有些类似rust中的枚举.
```cpp
union u_box {
  struct box st_box;     
  unsigned int ui_box;
};
```

bit field重新定义变量大小,需要的时候再去查
```cpp
struct _PRCODE
{
	unsigned int code1: 2;
	unsigned int cdde2: 2;
	unsigned int code3: 8;
};
```

# extern
C++支持函数重载，C++函数编译后生成的符号带有函数参数类型的信息，而C则没有。

例如int add(int a, int b)函数经过C++编译器生成.o文件后，add会变成形如add_int_int之类的, 而C的话则会是形如_add, 就是说：相同的函数，在C和C++中，编译后生成的符号不同。

这就导致一个问题：如果C++中使用C语言实现的函数，在编译链接的时候，会出错，提示找不到对应的符号。此时extern "C"就起作用了：告诉链接器去寻找_add这类的C语言符号，而不是经过C++修饰的符号。
```cpp
// c语言中不支持extern "C",只有 extern.
extern "C" {
    int add(int x,int y);
}
```

# struct & class
两者区别不大,cpp中,struct和class都可以有析构函数,都可以继承和多态.
struct中默认权限是public,class中默认权限是private的.
struct定义基类和派生的例子:
```cpp
struct Shape {
    virtual double area() const = 0;
};

struct Circle : public Shape {
    double radius;
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14 * radius * radius;
    }
};

```
# explicit 

explicit 修饰构造函数时，可以防止隐式转换和复制初始化
explicit 修饰转换函数时，可以防止隐式转换，但按语境转换除外

https://github.com/pzxy/CPlusPlusThings/blob/master/basic_content/explicit/explicit.cpp

 - [ ] todo: 后面要仔细梳理一下这个类型转换问题.

 # friend
 友元提供了一种 普通函数或者类成员函数 访问另一个类中的私有或保护成员 的机制. 感觉很不好, 代码结构会非常乱. 了解一下,不用这东西.

 ```cpp
 class A{
public:
    A(int _a):a(_a){};
    // 类B是类A的友元，那么类B可以直接访问A的私有成员
    friend class B;
private:
    int a;
};

 ```

 # using
using 可以引入标识符（如函数名、变量名等）.引入就是从其定义所在的作用域引入到当前作用域中，使得当前作用域中也可以使用该标识符.
它的基本用法是:
```cpp
using 标识符（如函数名、变量名等）
using 别名 = 类型
```
例子:
```cpp
// 1. 使用命名空间
using namespace std;
// 2. 取别名,类似c中的typedef 
typedef vector<int> V1; 
using V2 = vector<int>;
```
还有一些偏的用法,了解就行
```cpp
// 1. 改变访问权限,私有继承,却可通过 using来访问
class Derived : private Base {
    public:
    using Base::size;
    protected:
    using Base::n;
};
// 2. 重载,这里有两个f函数.Derived对象调用f(),会调用base中的f()方法.
class Derived : private Base {
    public:
        using Base::f;
        void f(int n){
            cout<<"Derived::f(int)"<<endl;
        }
};
```

# ::
- 全局作用域符（::name）：用于类型名称（类、类成员、成员函数、变量等）前，表示作用域为全局命名空间
- 类作用域符（class::name）：用于表示指定类型的作用域范围是具体某个类的
- 命名空间作用域符（namespace::name）:用于表示指定类型的作用域范围是具体某个命名空间的
```cpp
int count1=0;    // 全局(::)的count

class A {
public:
    static int count2;  // 类A的count (A::count)
};

int A::count2;
::count1=1; // 设置全局的count1为1
A::count2=2; // 设置类A的count2为2
```
# enum
枚举类型是一种类型,值的内存布局和整数一样,默认从0开始填充.但是是另外一种类型,所以和整数不能相互赋值.
```cpp
// 值分别为7、1、2、3、4、5、6。
// 可以进行赋值和关系运算(==,>=等),以及标准输出.
enum week {Sun=7, Mon=1, Tue, Wed, Thu, Fri, Sat};
cout << week::Sun << endl; 
```
枚举类,有了区域限制 ,但类中不能有方法.
```cpp
enum class week {Sun=7, Mon=1, Tue='a', Wed, Thu, Fri, Sat};
// 98
cout << static_cast<int>(week::Wed) << endl;
// b
cout << static_cast<char>(week::Wed) << endl;
```

# decltype
判断表达式的类型`decltype (expression)`
```cpp
int i = 4;
decltype(i) a; //推导结果为int。a的类型为int。
// 与using/typedef合用
using size_t = decltype(sizeof(0));
// 泛型
template <typename T>
auto multiply(T x, T y)->decltype(x*y)
{
	return x*y;
}
```
- [ ] todo: 左值右值这些.如果e是一个被重载的函数，则会导致编译错误。 否则 ，假设e的类型是T，如果e是一个将亡值，那么decltype（e）为T&& 否则，假设e的类型是T，如果e是一个左值，那么decltype（e）为T&。 否则，假设e的类型是T，则decltype（e）为T。

# define
定义一段字符,在引用的地方替换掉.
不到万不得已,不去用宏.
```cpp
#define PI 3.1415926
// 宏定义中的参数必须用括号括起来，以避免优先级问题
#define MAX(a, b) ((a) > (b) ? (a) : (b))
```
