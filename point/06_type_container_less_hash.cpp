
#include <algorithm>  // std::sort
#include <functional> // std::less/greater/hash
#include <iostream>   // std::cout/endl
#include <string>     // std::string
#include <vector>     // std::vector

using namespace std;

int main()
{
     // 初始数组
     vector<int> v{13, 6, 4, 11, 29};
     for (auto i = v.begin(); i != v.end(); i++)
     {
          cout << *i << " ";
     }
     cout << endl;

     // 从小到大排序
     sort(v.begin(), v.end());
     for (auto i = v.begin(); i != v.end(); i++)
     {
          cout << *i << " ";
     }

     // 从大到小排序
     sort(v.begin(), v.end(),
          greater<int>());
     for (auto i = v.begin(); i != v.end(); i++)
     {
          cout << *i << " ";
     }

     cout << hex;

     auto hp = hash<int *>();
     cout << "hash(nullptr)  = "
          << hp(nullptr) << endl;
     cout << "hash(v.data()) = "
          << hp(v.data()) << endl;
     cout << "v.data()       = "
          << static_cast<void *>(v.data())
          << endl;

     auto hs = hash<string>();
     cout << "hash(\"hello\")  = "
          << hs(string("hello")) << endl;
     cout << "hash(\"hellp\")  = "
          << hs(string("hellp")) << endl;
}