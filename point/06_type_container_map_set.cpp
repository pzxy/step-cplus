#include <functional>
#include <map>
#include <set>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void map_set()
{
    cout << "map_set" << endl;
    // set & map 都是有序的，打印的时候是从小到大的顺序
    set<int> s = {2, 1, 3, 4, 5};
    s.insert(6);
    for (auto &value : s)
    {
        cout << value << endl;
    }
    if (s.find(100) == s.end())
    {
        cout << "100 not found" << endl;
    }

    map<int, string> m = {{3, "a"}, {2, "b"}, {4, "c"}};
    m.insert({1, "d"});
    m[3] = "b";
    for (auto &value : m)
    {
        cout << value.first << " " << value.second << endl;
    }
    if (m.find(100) == m.end())
    {
        cout << "100 not found" << endl;
    }
    // 多重映射 multimap,这个了解，用的时候再去看api

    multimap<string, int> mmp{
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4}};
    for (auto &value_compare : mmp)
    {
        cout << value_compare.first << " " << value_compare.second << endl;
    }
    // find(k) 可以找到任何一个等价于查找键 k 的元素（!(x < k || k < x)）
    // lower_bound(k) 找到第一个不小于查找键 k 的元素（!(x < k)）
    // upper_bound(k) 找到第一个大于查找键 k 的元素（k < x）
}

void unorder_map_set()
{
    cout << "\norder_map_set" << endl;
    // 无序操作的性能比有序操作的性能高，能达到O(1),但是如果操作经常hash冲突，那么性能就会下降，最差是O(n)。
    unordered_set<int> s = {2, 1, 1, 3, 2, 3, 4, 5};
    for (auto &v : s)
    {
        cout << v << endl;
    }
}

int main()
{
    map_set();
    unorder_map_set();
}