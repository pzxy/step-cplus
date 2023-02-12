#include <iostream>
#include <vector>
using xbytes_t = std::vector<std::uint8_t>;
void print_bytes(xbytes_t b);
int main()
{
    using namespace std;
    // string to bytes
    std::string s1 = R"(hello world)";
    xbytes_t b1 = {std::begin(s1), std::end(s1)};
    std::cout << "b1: ";
    print_bytes(b1);

    // bytes to string
    xbytes_t b2 = {104, 101, 108, 108, 111, 32, 119, 111, 114, 108, 100};
    std::string s2 = {std::begin(b2), std::end(b2)};
    std::cout << "s2: " << s2 << std::endl;

    // int to string
    int i3 = 9527;
    auto s3 = std::to_string(i3);
    std::cout << "s3: " << s3 << std::endl;

    // string to int
    std::string s4 = "4444";
    std::string s4_f = "4444.3";
    int i4 = std::atoi(s4.data());
    float f4 = std::atof(s4_f.data());
    std::cout << "i4: " << i4 << std::endl;
    std::cout << "f4: " << f4 << std::endl;

    // int to bytes , BigEnded
    int i5 = 258;
    int size4 = 4;
    std::vector<uint8_t> b5(size4, 0);
    for (int i = 0; i < size4; i++)
    {
        b5[size4 - 1 - i] = (i5 >> (i * 8));
    }
    std::cout << "b5: ";
    print_bytes(b5);

    // bytes to int , BigEnded
    xbytes_t b6 = {0, 0, 1, 2}; // 258
    int i6;
    int size6 = b6.size();
    for (int i = 0; i < size6; i++)
    {
        i6 += b6[size6 - 1 - i] << (8 * i);
    }
    std::cout << "i6: " << i6 << std::endl;

    // insert string
    string s7 = "three";
    string s7_2 = "one two ";
    s7.insert(0, s7_2); // 在原串下标为0的字符前插入字符串
    cout << "s7: " << s7 << endl;

    string s7_3 = "one ";
    char c7 = 't';
    s7_3.insert(4, 5, c7); // 在原串下标为4的字符前插入5个字符
    cout << "s7_3: " << s7_3 << endl;

    string s7_5 = " two three";
    string s7_6 = "oneline";
    s7_5.insert(0, s7_6, 0, 3); // 将字符串s2从下标为1的e开始数3个字符，分别是eak，插入原串的下标为0的字符h前
    cout << "s7_5: " << s7_5 << endl;

    // insert bytes && implment append by insert
    auto append = [](xbytes_t &a, xbytes_t &b)
    {
        a.insert(a.end(), b.begin(), b.end());
    };
    xbytes_t b8 = {0, 0, 1, 0};
    xbytes_t b8_2 = xbytes_t(4, 0); // 0 0 0 0
    append(b8, b8_2);
    cout << "b8: ";
    print_bytes(b8);
}

void print_bytes(xbytes_t b)
{
    for (auto const &v : b)
    {
        std::cout << (int)v << ' ';
    }
    std::cout << std::endl;
}