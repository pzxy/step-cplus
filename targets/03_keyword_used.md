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
    // 必须x等于7,否则报错
    assert(x==7); 
    return 0; 
} 
```
# const
const常量具有类型，编译器可以进行安全检查；#define宏定义没有数据类型，只是简单的字符串替换，不能进行安全检查
const常量支持所有类型
其他情况下它只是一个 const 限定的变量，不要将与常量混
