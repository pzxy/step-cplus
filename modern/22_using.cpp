#include <iostream>
#include <string>
#include <map>
using namespace std;

// 1. 别名
using func2 = void (*)(int, int);
// 2. 别名模版

template <class T>
using int_map = std::map<int, T>;
int main()
{
    int_map<std::string> int2string;
    int2string[11] = "7";
}