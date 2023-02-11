#include <iostream>
#include <vector>
using xbytes_t = std::vector<std::uint8_t>;
void print_bytes(xbytes_t b);
int main()
{
    // string to bytes
    std::string s = R"(hello world)";
    xbytes_t b = {std::begin(s), std::end(s)};
    std::cout << "b1: ";
    print_bytes(b);

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

    // int to bytes
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
}

void print_bytes(xbytes_t b)
{
    for (auto const &v : b)
    {
        std::cout << (int)v << ' ';
    }
    std::cout << std::endl;
}