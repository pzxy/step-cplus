#include <iostream>
using namespace std;
// 优先使用make_unique,make_shared 而不是 new来创建智能指针。
// 1. 和直接使用new相比，make函数消除了代码重复，提高了异常安全性。对于std::make_shared和std::allocate_shared，生成的代码更小更快。
// 2. 不适合使用make函数的情况包括需要指定自定义删除器和希望用花括号初始化。
// 3. 对于std::shared_ptrs，其他不建议使用make函数的情况包括(1)有自定义内存管理的类；(2)特别关注内存的系统，非常大的对象，以及std::weak_ptrs比对应的std::shared_ptrs活得更久。
// 4. c++11没有make_unique，c++14才有呢。
int main() {}