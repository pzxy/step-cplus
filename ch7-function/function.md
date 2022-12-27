# 定义函数
```c++
// 没有返回值的函数
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