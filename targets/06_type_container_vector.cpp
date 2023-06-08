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

int main()
{
    iteratorsVector();

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