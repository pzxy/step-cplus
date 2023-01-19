#include <iostream>
#include <array>
int main()
{
    using namespace std;

    array<int, 4> a = {1, 2, 3, 4};
    array<int, 4> b;
    b = a;
    cout << b[1];
}
