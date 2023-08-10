#include <iostream>
using namespace std;
// NULL 底层类型是 int，默认值是0，可能会被隐式转换为0
// nullptr 是一个新的类型。
// nullptr的出现消除了使用0带来的二义性，与此同时其类型和
// 含义也更加明确。含义明确的好处是，C++标准可以加入一系列明确的
// 规则去限制nullptr的使用，这让程序员能更快地发现编程时的错
// 误。所以建议读者在编译器支持的情况下，总是优先使用nullptr而 非0
int mian()
{
    std::string s1(false);// 成功，false = 0，0->为const char * const
    std::string s2(true);// 失败
}
