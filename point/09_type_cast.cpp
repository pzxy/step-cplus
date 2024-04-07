#include <iostream>
#include <string>
#include <vector>
using namespace std;
void string2char()
{
    cout << "> string to char" << endl;
    string s = "hello world";
    const char *c = s.c_str();
    cout << c[2] << endl;
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
    string s = "10086 world";
    vector<uint8_t> bytes{s.begin(), s.end()};
    std::cout << "string: " << s << std::endl;
    cout << "string[3]: " << bytes[3] << endl;
    cout << "Bytes: ";
    for (auto b : bytes)
    {
        cout << hex << static_cast<int>(b) << " ";
    }
    cout << endl;
}

void int2long()
{
    cout << "> int2long" << endl;
    int i = 13;
    long l = (long)i;          // c中的类型转换，没有过多的类型校验。
    l = static_cast<long>(13); // c++中的类型转换，编译器会检查类型。
    cout << dec << l << endl;
}

void int2string()
{
    cout << "> int2string" << endl;
    int i = 123;
    string s = to_string(i); // c++ 11
    cout << s << endl;
}

void int2bytes()
{
    cout << "> int2bytes" << endl;
    unsigned char bytes[] = {0x1, 0x2, 0x3, 0x4};
    int result = (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3];
    cout << dec << result << endl;
}


int main()
{
    string2char();
    string2int();
    string2byte();
    int2long();
    int2string();
    int2bytes();
}