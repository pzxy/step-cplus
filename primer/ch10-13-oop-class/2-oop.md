# 继承

派生类可以访问基类中非私有成员。不想被继承的成员可以设置为 private。

```c++
// 基类
class Animal {
    // eat() 函数
    // sleep() 函数
};


//派生类,此时Dog拥有了 eat()， sleep()，bark()
class Dog : public Animal {
    // bark() 函数
};

// 多继承
class Dog : public Animal, 别的类 {
    // bark() 函数
};
```

# 重载
函数名称相同，但函数签名不同。
```C++
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
# 多态

多态按字面的意思就是多种形态。一般利用这种特性来构建一些框架，起到控制反转的效果。

例子：[polymorhism.cpp](./polymorphism.cpp)

# 纯虚函数

需要 virtual 来创建。只需要声明，没有函数体，需要派生类去实现。类似java中的抽象函数。

```c++
class Shape {
   protected:
      int width, height;
   public:
      Shape( int a=0, int b=0)
      {
         width = a;
         height = b;
      }
      // pure virtual function
      virtual int area() = 0;
};
```
# 接口
接口描述了类的行为和功能，而不需要完成类的特定实现。

C++ 接口是使用抽象类来实现的，抽象类与数据抽象互不混淆，数据抽象是一个把实现细节与相关的数据分离开的概念。

如果类中至少有一个函数被声明为纯虚函数，则这个类就是抽象类。纯虚函数是通过在声明中使用 "= 0" 来指定。

在c++后面出现的高级语言接口和类或者结构体在代码构造上是完全分开的。


例子:[interface.cpp](interface.cpp)

