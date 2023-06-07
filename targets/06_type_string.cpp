#include <string>
#include <iostream>
#include <cassert>

using namespace std;

void iteratorString()
{
    // cbgein cend begin end rbegin rend
    string s1 = "Hello world";
    cout << s1 << endl;
    /**
     * 迭代器
     */
    string::iterator it = s1.begin();
    // H
    cout << *it << endl;
    // h
    *it = 'h';
    cout << *it << endl;
    // e
    cout << *(it + 1) << endl;
    // 不可修改的迭代器
    auto it2 = s1.cbegin();
    cout << *it2 << endl;

    // end指向一个 \0, 它也是0
    string::iterator iend = s1.end();
    if (*iend == '\0')
    {
        cout << "end" << endl;
    }
    if (*iend == 0)
    {
        cout << "end" << endl;
    }

    // 倒叙迭代
    string::reverse_iterator rit = s1.rbegin();
    // 输出d l
    cout << *rit << endl;
    cout << *(rit + 1) << endl;
}
/**
 * Element access
 */
void accessString()
{
    cout << "accessString" << endl;
    string s1 = "Hello world";

    s1.at(0) = 'h';
    cout << s1 << endl; // hello world

    s1.front() = 'H';
    cout << s1 << endl; // Hello world

    s1.back() = 'D';
    cout << s1 << endl; // Hello worlD

    cout << s1[0] << endl; // H
    // length 和 size是一样的，没有区别。
    cout << s1.length() << endl; // 11
    cout << s1.size() << endl;   // 11

    std::string s2 = "super man";
    // s2.data() 返回一个指向字符串首字符的指针，
    // s2.begin() 返回一个指向字符串首字符的迭代器，和 s2.data()并不相等。
    assert(s2 == s2.data()); // 这里之所以相等是因为 std::string 重载了 == 操作符
    assert('s' == s2.data()[0]);
    assert(s2.size() == std::strlen(s2.data())); // 条件为真则不会发生任何事情
    assert(std::equal(s2.begin(), s2.end(), s2.data()));
    assert(std::equal(s2.data(), s2.data() + s2.size(), s2.begin()));
}

/**
 * Capacity 容量
 */
void capacityString()
{
    cout << "capacityString" << endl;
    string s1 = "Hello world";
    assert(s1.empty() == false);
    assert(s1.size() == 11); // szie 和 length 是一样的，size是string作为容器来看时的使用的。
    assert(s1.length() == 11);
    cout << s1.max_size() << endl; // 这是值时非常大的，是可用虚拟内存的大小。
    s1.reserve(100);               // 至少保留100大小以后才能重新分配内存。
    assert(s1.capacity() >= 111);  // 11 + 100
    s1.resize(200);                // 设置总大小。也就是 size()的值。在go中是len的大小。
    assert(s1.size() == 200);
    auto before_cap = s1.capacity();
    s1.shrink_to_fit();           // 释放多余空间。 并不一定会减少到cap和len一样大小。但是cap会减少。
    assert(s1.capacity() < before_cap); // 

    // 总结一下：
    //  s1.size() 就是go中的len，
    //  capacity() 就是 cap
    //  s1.resize(200) 将 len设置成200大小，多删少则用默认值补齐。
    //  s1.reserve(100) 不会改变len的值，只是增加了cap的值。含义是至少再有100的数据后才会重新分配内存。
    //  shrink_to_fit() 释放多余未使用的空间。并不一定会将cap减少到和len一样大小。但是cap会减少。
}

int main()
{
    // iteratorString();
    // accessString();
    capacityString();
}