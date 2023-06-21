#include <iostream>
#include <string>
using namespace std;
void string2char()
{
    cout << "> string to char" << endl;
    string s = "hello world";
    const char *c = s.c_str();
    cout << c << endl;
}

void string2int()
{
    cout << "> string to int" << endl;
    string s = "10086";
    int i = std::stoi(s);
    cout << i << endl;
}

void string2byte()
{
    cout << "> string to bytes" << endl;
}

int main()
{
    string2char();
    string2int();
    string2byte();
}