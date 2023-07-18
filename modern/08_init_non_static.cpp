#include <iostream>
#include <bitset>
using namespace std;
// 1. 使用默认初始化。
// C++11之前要初始化每个变量。即使构造函数用不到。比如： X() : a_(0), b_(0.), c_("hello world") {}
// C++11之后只需要初始化自己需要的。比如：X(int a) : a_(a) {}

// 2. 位域初始化
// 注意如果用选择表达式的话，要小心，具体规则用的时候再去看书。
struct S
{
    int y : 8 = 11; // 00001011
    int z : 4 = 7;  // 00000111
};
void demo2()
{
    cout << "> demo2" << endl;
    S s;
    cout << "y:" << bitset<32>(s.y) << endl;
    cout << "z:" << bitset<32>(s.z) << endl;
}
int main()
{
    demo2();
}