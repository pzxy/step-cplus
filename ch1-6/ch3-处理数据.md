# 简单变量
变量名要求：不要整活儿就行。

## 1. 整型
short：至少16位，是 short int 简称
int： 至少等于short
long：至少32，且至少等于int。long int 简称
long long：至少64
总结：现在的系统基本上都是64位的，直接理解int 就是 int32， long long就是int64 
在go的int，32位系统是int32，64位系统是int64.
rust什么样子的？
##  2. 常量
![1.png](./image/ch3.1.png)
![2.png](./image/ch3.2.png)
预处理：`#define INT_MAX 32767` 将文件中所有INT_MAX都替换成32767，类似别的语言中的常量，或者全局变量。

## 3. c++11
```c++
int a = 7
int b{7}
int c = {7}
```
可以理解接受一个匿名函数的返回值。

## 4. 无符号类型
```c++
unsigned short change;
unsigned int a;
unsigned b; // 就是 unsigned int b
```
溢出：就是正常溢出，rust中溢出直接panic。

## 5. 进制
```c++
unsigned int a = 0x42;//16进制，一般都是 unsigned 类型，因为16进制常用来表示地址，没有负数。
int b = 042;//8进制 
```

##  6. char类型
```c++
char ch = 'M';
int i = ch; 	// i = 77
ch = ch + 1;	// ch = N
// 输出字符,下面两个都输出 N,因为上面 M ，+1了
cout << ch << endl;
cout.put(ch);

// char不属于以下任何一种
unsigned char bar;// 无符号类型 ，0-255 ，能表示更多的类型，ASSIC选择任何都行
signed char snark;// 有符号类型
```
## 7. wcha_t

## 8. bool
```c++
bool ready = true;
int a = true;//1
int b = false;//0
```

# const
```c++
const int toes = 10;// 替代 #define
```
# 浮点数
表示很大很小的数字，具体实现简单来说就是用来表示二进制小数的方式，用几个bit位来描述小数点需要偏移的位置。
```c++
12.34
0.03
8.0
E6 // 1000000
3.45E6 // 3450000
7e5 // 700000
e+2 // 100 +号表示小数点右移动
e-2 // 0.01 -表示小数点左移动
float a = 10.0; // 6位有效位
double b = 10.0; // 15位有效位置
const float c = 1.0e6;
```
## 1. cout.setf()
cout打印33.250000 为 33.35，

# c++运算符
和其他高级语言区别不大。
c11中 auto 就是自动推倒类型。
```c++
auto a = 100;// int类型
auto b = 1.5; // double类型
auto c = 1.4e12L;// long double类型
```

