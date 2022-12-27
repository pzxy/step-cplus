# 定义函数
```c++
// 没有返回值的函数,可有原型，也可没有原型
void functionName(parameterList);
void functionName(parameterList)// void functionName(int n)
{
    statements(s)
    return;
}
```
# 函数和数组

```c++
// 这里的数组和int *arr是等价的， 都意味着arr是一个int指针。
// 所以在函数中修改arr中的值，函数外面的arr的值也会变化。
// 但是这个等价只有在函数签名中可以用，别的上下文中是不一样的，比如
// 在函数体中不能使用int tip[]来声明指针。
int sum_arr(int arr[],int n);
//  使用const关键字使这个arr在函数中无法被修改。
int sum_arr(const int arr[],int n);
```

# 指针和const
```c++
// 不能通过 *pt来修改age的值，但是可以通过修改age的值来影响到*pt的值。
int age = 39;
const int * pt = &age;
// 允许
const int age = 39;
const int * pt = &age;
// 非法的写法，不能将一个const的地址赋值给指向const的指针。 
const int age = 39;
int * pt = &age;
```

# 函数和string对象
```c++
#include<string>
```

# 函数和array对象
array就是一个结构体，可以作为参数，入参可以是指针类型等
```c++
#include <array>
#include <string>
const std::array<std::string,4> snames = {"Spring","Summer","Fall","Winter"};
// 一个传指针，一个传原型
void fill(std::array<double,Seasons> * pa);
void fill(std::array<double,Seasons> pa);
```

# 函数指针
和数据一样，函数也是有地址的，函数的地址是存储机器语言代码的内存的开始地址。在rust中可以通过`fn`关键字来创建一个函数，其实就是创建一个函数指针类型。
```c++
// 1. 获取函数的地址
think() // 这是一个函数
think // 这是函数的地址

// 2. 声明函数指针和声明指针是类似的，
int *a;//这是声明一个int类型的指针
// 声明一个函数指针,函数指针就是将函数名用 (*pf) 替换掉，如果pam是一个函数，那么(*pf)也是一个函数，pf就是这类函数的指针。
double pam(int);
double (*pf)(int);
// 这两种写法是不一样的
double (*pf)(int); // (*pf)(int)意味着pf是一个指向函数的指针。
double *pf(int);// pf是一个返回指针的函数。

// 3. 用法,最后目的就是可以将函数作为参数，这点在别的高级语言中很常见。
double pam(int);
void estimate(int lines,double (*pf)(int));
estimate(50,pam)// 将pam()的地址传进去

// 4. 使用函数指针来调用函数,将 (*pf) 看作函数名
double pam(int);
double (*pf)(int);
pf=pam;
double x=pam(4);
// 这两种方式都可以，第一种是本质
double y=(*pf)(5);
double y=pf(5);
```
