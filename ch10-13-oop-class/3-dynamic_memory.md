# 动态内存
在有自动垃圾回收的语言中，是不需要去关心动态内存的。比如go，java。
在rust中通过所有权，借用，生命周期等概念来控制变量的创建和销毁。
在c++中，堆上的数据，需要手动来创建和销毁。
在c++中，使用`new`关键字在堆上分配空间并创建对象，`delete`关键字来释放空间。

基本语法:
```C++
new data-type;
delete pvalue;

```

分配空间的时候可能空间大小不够了，需要判断以下。
```c++
double* pvalue  = NULL;
if( !(pvalue  = new double ))
{
   cout << "Error: out of memory." <<endl;
   exit(1);
}
```

完成例子:
```c++
#include <iostream>
using namespace std;
int main ()
{
   double* pvalue  = NULL; // 初始化为 null 的指针
   pvalue  = new double;   // 为变量请求内存
   *pvalue = 29494.99;     // 在分配的地址存储值
   cout << "Value of pvalue : " << *pvalue << endl;
   delete pvalue;         // 释放内存
   return 0;
}
```

# 数组的动态内存分配
```c++
// 动态分配,数组长度为 m
int *array=new int [m];
//释放内存
delete [] array;
```

# 对象的动态内存分配
```c++
#include <iostream>
using namespace std;
 
class Box
{
   public:
      Box() { 
         cout << "调用构造函数！" <<endl; 
      }
      ~Box() { 
         cout << "调用析构函数！" <<endl; 
      }
};
 
int main( )
{
   // 构造函数和析构函数会被调用四次
   Box* myBoxArray = new Box[4];
 
   delete [] myBoxArray; // 删除数组
   return 0;
}
```