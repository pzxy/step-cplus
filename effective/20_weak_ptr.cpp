#include <iostream>
using namespace std;
// 1. weak_ptr的实现原理是，在shared_ptr对象外面再增加一个 弱引用计数来实现的。
// 因此，里面的shared_ptr数据可能为空。
// 2. weak_ptr可以打破shared_ptr的循环引用问题。
// 3. weak_ptr不能使用 * 和 -> ，使用的时候通过 .lock() 转成shared_ptr来用。
// 4. share_ptr对象可以直接赋值给weak_ptr对象。

int main() {}