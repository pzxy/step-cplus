[基本类型](#基本类型)
[修饰符类型](#修饰符类型)
# 基本类型
|类型|关键字|
|-|-|
|布尔型|bool|
|字符型|char|
|整型|int|
|浮点型|float|
|双浮点型|double|
|无类型|void|
|宽字符型|wchar_t|

字符型char只占八位，存储ascii码的，而宽字符型是为了存储多国语言的代码unicode。
```cpp
// 宽字符型的定义
typedef short int wchar_t;
```
# 修饰符类型
c++允许在 char、int 和 double 数据类型前放置修饰符

|类型|解释|
|-|-|
|signed|表示变量可以存储负数。对于整型变量来说，signed 可以省略，因为整型变量默认为有符号类型。|
|unsigned|表示变量不能存储负数。对于整型变量来说，unsigned 可以将变量范围扩大一倍。|
|short|表示变量的范围比 int 更小。short int 可以缩写为 short。|
|long|表示变量的范围比 int 更大。long int 可以缩写为 long。|
|long long|表示变量的范围比 long 更大。C++11 中新增的数据类型修饰符。|
|float|表示单精度浮点数。|
|double|表示双精度浮点数。|
|bool|表示布尔类型，只有 true 和 false 两个值。|
|char|表示字符类型。|
|wchar_t|表示宽字符类型，可以存储 Unicode 字符。|