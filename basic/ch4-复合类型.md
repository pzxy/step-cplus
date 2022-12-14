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

# 结构体
```c++

```