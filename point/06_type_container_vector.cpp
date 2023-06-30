#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;
void iteratorsVector()
{
    cout << "iteratorsVector" << endl;
    vector<int> vec = {5, 4, 3, 2, 1};
    for (auto &value : vec)
    {
        cout << value << endl;
    }
    std::sort(vec.begin(), vec.end());
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        std::cout << *i << std::endl;
    }
}

void crudVector()
{
    cout << "curdVector" << endl;
    vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6);
    assert(vec.back() == 6);
    vec.pop_back();
    assert(vec.back() == 5);
    vec.reserve(100);
    assert(vec.capacity() == 100);
    vec.resize(20);
    assert(vec.size() == 20);
    vec.insert(vec.begin() + 10, 100);
    assert(vec[10] == 100);
    vec.erase(vec.begin() + 10);
    assert(vec[10] == 0);
    vec.emplace(vec.begin() + 10, 100);
    assert(vec[10] == 100);
    vec.emplace_back(33);
    assert(vec.back() == 33);
    vec.clear();
    assert(vec.size() == 0);
}

class Obj1
{
public:
    Obj1()
    {
        cout << "Obj1()\n";
    }
    Obj1(const Obj1 &)
    {
        cout << "Obj1(const Obj1&)\n";
    }
    Obj1(Obj1 &&)
    {
        cout << "Obj1(Obj1&&)\n";
    }
};

class Obj2
{
public:
    Obj2()
    {
        cout << "Obj2()\n";
    }
    Obj2(const Obj2 &)
    {
        cout << "Obj2(const Obj2&)\n";
    }
    Obj2(Obj2 &&) noexcept
    {
        cout << "Obj2(Obj2&&)\n";
    }
};

void noexceptVector()
{
    // push_back、insert、reserve、resize 会导致内存重新分配。
    // 如果没有实现移动构造就会调用复制构造函数，影响性能。
    // 如果要实现了移动构造，那么移动构造要加上 noexcept，否则还是会调用复制构造函数，导致内存重新分配失败。
    // 需要注意的是push和pop函数适合在尾部进行操作，只有在尾部操作的时候，性能才很高呢。
    cout << "noexceptVector" << endl;
    vector<Obj1> v1;
    v1.reserve(2);
    cout << "可以看到obj1没有" << endl;
    v1.emplace_back();
    v1.emplace_back();
    v1.emplace_back();

    vector<Obj2> v2;
    v2.reserve(2);
    v2.emplace_back();
    v2.emplace_back();
    v2.emplace_back();
}

int main()
{
    iteratorsVector();
    crudVector();
    noexceptVector();
}