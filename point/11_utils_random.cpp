#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    srand(time(nullptr)); // 给随机数一个种子，让随机数每次都不同。
    int r = rand();
    cout << "rand: " << r << endl;
    int num = r % 100 + 0;
    cout << "num: " << num << endl;
}