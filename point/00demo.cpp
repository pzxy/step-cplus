#include <iostream>
using namespace std;


struct A
{
    int a;
};
void fa(A & a) {
    cout << a.a << endl;
    a.a = 5;
    return ;
}

int main()
{
    int n;
    // 这里的*表示指针pt是一个地址
    int *pt = new int;
    const int b = 101;
    // 这里获取n的引用,要注意.
    // &可以取地址，也可以表示引用类型。
    // 如果&表示类型的话，应该当成整体看待，也就是说int& 是一个类型,通用表示的话是 T&
    int &rn = n;// 此时 rn 和 n是一个东西。
    // 这里的*是一个解引用操作符,会访问地址指向空间的值.
    // 上面提到了 pt表示一个地址,所以这里的*pt就是获取pt指向的值
    int &rt = *pt;
    // 这里也可以将 const int & 看成一个整体.通用表示的话是 const T&
    // 因为b是const int类型,要获取b的引用,规定只能是const T& 类型.
    const int &rb = b;
    cout << n << endl;// n是1，实际上是个任意的值。
    cout << rn << endl;//1 因为rn是n的引用。
    cout << *&rn << endl;// 1，&获取rn取地址，*再访问rn的地址，读出来还是n的值。

    A a;
    a.a = 4;
    A & aa = a;
    fa(aa);
    cout << a.a << endl;
}