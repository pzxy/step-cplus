#include <iostream>
using namespace std;
// 1. shared_ptr对象比unique_ptr大两倍。unique_ptr更接近原生指针。
// 2. shared_ptr删除资源通过delete，也可以自定义自己的删除器。
// 3. 避免从原始指针上创建shared_ptr,因为会导致double-free问题。
// 4. 当两个类中都有shared_ptr时，要注意循环引用问题。
// 5. shared_ptr适用于共享资源。

int main() {}