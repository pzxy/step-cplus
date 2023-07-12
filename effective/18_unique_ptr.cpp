#include <iostream>
using namespace std;

// 1. auto_ptr有悬垂指针问题，unique_ptr能直接检查出来
// 2. unique_ptr对象赋值到另外一个的时候要用std::move(p1)，一般常见的是作为工厂方法返回值来用。
// 3. shared_ptr<int> p2 = std::move(p1); 可以直接将unique_ptr数据转成shared_ptr类型。


int main() {}