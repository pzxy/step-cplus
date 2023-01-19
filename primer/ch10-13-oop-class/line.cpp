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