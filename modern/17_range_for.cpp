#include <iostream>
using namespace std;
// for(auto n : x) 循环多少次，调用多少次复制构造函数。
// 所以推荐用for(const auto &n:x)
// begin 和 end 函数不比返回相同的类型。只要返回值能进行boolean比较就好了。

class T
{
    std::vector<int> data_;

public:
    std::vector<int> &items() { return data_; }
};
T foo()
{
    T t;
    return t;
}
// 这里有问题，因为foo()中的t是一个临时变量，函数退出以后t会析构掉，所以有问题。
for (auto &x : foo().items())
{
} // 未定义行为


// 最后如何实现一个基于范围的for循环的类？用到的时候再看书。
int main()
{
}