```cpp

set<int> s = {7, 3, 9};           // 定义集合并初始化3个元素

for(auto& x : s) {                // 范围循环输出元素
    cout << x << ",";              // 从小到大排序，3,7,9
}   

auto comp = [](auto a, auto b)  // 定义一个lambda，用来比较大小
{   
    return a > b;                // 定义大于关系
};  

set<int, decltype(comp)> gs(comp)  // 使用decltype得到lambda的类型

std::copy(begin(s), end(s),          // 拷贝算法，拷贝数据
          inserter(gs, gs.end()));  // 使用插入迭代器

for(auto& x : gs) {                // 范围循环输出元素
    cout << x << ",";                // 从大到小排序，9,7,3
}  
```