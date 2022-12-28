# 概念
面向对象时将万物都看成对象，类是对对象的抽象，对象的能力是通过方法赋予的。
相比面向过程，面向对象可以更好的抽象事物的一些特点，特别是面对一些复杂的大工程，是一个不错的开发方式。而面向过程是更直接的一种编程方式。只要写出的代码扩展性强，容易阅读，至于是面向过程还是面向对象其实并不重要。
# 定义
```C++
class classname // 类名
{
    Access specifiers: // 访问修饰符: private/public/protected
        Date members/variables; // 变量
        Member functions(){} // 方法
}; // 分号结束一个类
```
例子：[box.cpp](./box.cpp)

# 类成员函数
把定义和原型写在类定义内部的函数
# 构造函数
构造函数名称和类名完全相同，不会返回任何类型，也不会返回void，可为某些成员变量设置初始值。它会在每次创建类的新对象时执行。和java里面的构造函数差不多。

构造函数可以带参数，也可以不带参数。
```c++
class Line
{
   public:
      Line(double len);  // 这是构造函数
 
   private:
      double length;
};
 
// 成员函数定义，包括构造函数
Line::Line( double len)
{
    cout << "Object is being created, length = " << len << endl;
    length = len;
}

// 程序的主函数
int main( )
{
   // 如果不带参数，则 Line line;
   Line line(10.0);
}

```
# [析构函数](./line.cpp)
析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀，它不会返回任何值，也不能带有任何参数。它会在每次删除所创建的对象时执行。析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。

```c++
#include <iostream>
using namespace std;
class Line
{
   public:
      Line();   // 这是构造函数声明
      ~Line();  // 这是析构函数声明
};
// 成员函数定义，包括构造函数
Line::Line(void)
{
    cout << "Object is being created" << endl;
}
Line::~Line(void)
{
// 程序结束时这一行会被打印。
    cout << "Object is being deleted" << endl;
}
// 程序的主函数
int main( )
{
   Line line;
   return 0;
}
```


# 复制构造函数

一种特殊的构造函数，使用同一类中已有的对象来初始化创建的新对象。如果在类中没有定义拷贝构造函数，编译器会自行定义一个。如果类带有指针变量，并有动态内存分配，则它必须有一个拷贝构造函数。作用：
- 通过同类型的对象来初始化新创建的对象。
- 作为参数或者返回值，将对象赋值一份。

这个复制构造函数其实就相当于rust中的Clone trait，说Clone tarit也不恰当，因为这个Clone trait是我们手动调用的。那么好像Copy trait是比较像，其实也不是，因为copy只是一种标记方式，我们没有办法干预实现的。应该是自动调用的Clone trait，好像只能这么描述了。
其实就是提供了一种干预参数复制的方式。一个值作为参数传进去的时候，其实都会有一个临时变量来接一下这个值，这样就会有值的复制，而复制构造函数就是提供了一种手段，让在复制的时候调用我们的这个函数，用我们规定的方式就行复制。在rust中可以通过move的手段，直接转移所有权，不产生这个临时变量。在c++ 中我们可以用传递&的方式来绕过这种复制的操作，从而绕过这个复制构造函数。

复制构造函数形式:
```c++
classname (const classname &obj){
    // 构造函数主体
}
```
例子：[copy.cpp](copy.cpp)

# 友元函数，友元类
friend可以修饰函数或者类，让其访问自己的私有成员。

提供了一种方式可以让别人访问自己的私有成员。
为什么别的语言中没有这个功能呢？比如go语言。
因为在go中，可以直接访问同一个包中的其他结构的私有变量。准确的说go中的私有变量其实相当于 c++中的protected 限定。 而c++里面的这种友元类型，可以不在同一个包中也能访问私有变量，这种能力甚至超过了protected 简直不能理解。完全是引狼入室。


```C++
#include <iostream>
using namespace std;
class Box
{
   double width;
public:
   friend void printWidth( Box box );
   void setWidth( double wid );
};
// 成员函数定义
void Box::setWidth( double wid )
{
    width = wid;
}
// 请注意：printWidth() 不是任何类的成员函数
void printWidth( Box box )
{
   // 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 
   cout << "Width of box : " << box.width <<endl;
}
// 程序的主函数
int main( )
{
   Box box;
   // 使用成员函数设置宽度
   box.setWidth(10.0);
   // 使用友元函数输出宽度
   printWidth( box );
   return 0;
}
```