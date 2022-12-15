# 数组
```c++
// 声明1
int arr[3];
arr[0] = 1;
arr[1] = 2;
arr[2] = 3;
// 声明2，c11可省略等号
int arr2[3] = {1,2,3};
// 声明3
int arr3[3];
arr3 = {1,2,3};
// 声明4，第一个值为1，其他为0；c11可直接{}，都为0
int arr4[5] = {1} ;
// 声明5,自动推断
int arr5[] = {1,2,3} 
```
# 字符串
```c++
// 是char数组，是不是字符串
char dog[4] = {'a','b','c','d'};
// 是字符串
char dog2[4] = {'a','b','c','\0'};
// 字符串
char fish[] = "Bubbles"
// 单引号 表示 S 是83的另一种表示
char s = 'S';
// 双引号 这是两个字符 S和\0
char s2 = "S";
```

## 1. getline(), get()
位置： isstream, cin类
```c++
// 读取命令行输入，读取到换行(包括换行符)。读取到name数组中，读取20个字符
cin.getline(name,20);

// 读到换行符
cin.get(name，20);
// 读取到换行，不赋值给任何人。
cin.get();
// 读到换行符并读取掉他
cin.get(name,20).get();
```
常见问题：
使用getline()时，上个输入键入的回车如果没有被消耗掉会被直接读取。所以可以将get()放在getline()前来消耗掉这个回车。(cin >> year).get() 

# string类
string类也在std命名空间中，其实命名空间就相当于rust中的crate。而string其实就相当于java中的String对象一样。里面有一些方法。并且对操作符进行了重载。
string就是正常理解的字符串，可以做一些拼接等操作
使用： `#include<string>`
```c++
string str1;
string str2 = "1234567";
cin >> str1;
string str3 = {"asd"};// 引号可以省略

str1 = str2 ; // char数组是不可以的。
```
string类有一些size(), strlen(charr)等一些对字符串的操作。

# 结构
就是结构体
```c++
// 声明一个结构
struct inflatable
{
    char name[20];
    float volume;
    double pricle;
}

// 赋值变量
inflatable a  = {"Bambi",0.5,21.99};
inflatable guests[2] = 
{
    {"Bambi",0.5,21.99},
    {"Godzilla",2000,22.99}
}
// 声明和赋值
struct student
{
    int age;
} stu = 
{
    12 //age
}
```

# 共用体
类似rust中枚举类型

```c++
union one4all
{
    int int_val;
    long long_val;
    double double_val;
}
// 声明赋值
one4all pail;
// 在不同的时间可以存不同类型。但是同时只能存一种。内存大小为最大类型的大小。
pail.int_val = 12;
pail.double_val = 3.445;

// 可以在结构体中这样写
struct widget
{
    int type;
    union id 
    {
        long id_num;
        char id_char[20];
    } id_val;
};
```
# 枚举
类似java和go中的枚举类型。
```c++
enum spectrum{red,orange,yellow ,green,blue,violet,indigo,ultraviolet};

// 声明赋值
spectrum band;
band = blue;
band = orange;
band = spectrum(1)//orange
// 枚举量是整型，可以升级成int类型。
int color = bule；

// 如果只要枚举常量，这样创建，类似go中 iota
enum {red,orange,yellow ,green,blue,violet,indigo,ultraviolet};

// 枚举赋值，可以只赋值里面部分的常量值，需要的时候再看。
```

# 指针和自由存储空间
指针和c，rust中一样。只需要记住两点：
1. 指针是有类型的,要看声明类型。
2. 指针的值必须要由 &变量 获取。
```c++
int updates = 6;
int * p_updates;// 声明时 * 前后空格没什么用。甚至可以 int*p_updates
p_updates = &updates;
// 还可以
int higgens = 5；
int * pt = &higgens；
```
## 用new在堆上分配内存，delete释放内存
```c++
int * ps = new int;// 创建一个指针，指向int大小的空间
*ps = 1；// 使用指针


struct inflatable
{
    float volume;
}
inflatable * ps = new inflatable;
(*ps).volume; // 通过指针访问变量
delete ps; //释放ps

```

# 数组替代品 vector 和 array
vector在名称空间std中,动态数组，数据在堆中。
```c++
//创建0大小的数组或者int， vector<typeName> vt(n_elem)
vector<int> vi; 
vector<int> vi2(4); //里面4个元素
```
c++11 array，std中，数据在栈上，大小固定，快。要考虑overflow问题

```c++
// array<typeName,n_elem> arr;
array<int,5> ai;// 创建5个int的数组对象
array<int,5> a2 = {1,2,3,4,5};// 创建并赋值

```
异同：
1. array和vector都可以通过下标来访问。
2. array对象可以赋值给另一个array对象。对于数组，必须逐元素复制数组。如果array对象大小长度不同不能互相赋值。

注意：下标越界问题，尝试使用`a.at(1) = 23` 来访问下标。