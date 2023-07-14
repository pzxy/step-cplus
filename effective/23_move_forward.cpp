#include <iostream>
using namespace std;

// std::move执行到右值的无条件的转换，但就自身而言，它不移动任何东西。
// std::forward只有当它的参数被绑定到一个右值时，才将参数转换为右值。
// std::move和std::forward在运行期什么也不做。
int main() {}