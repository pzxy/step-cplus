
#include <algorithm>  // std::copy
#include <iterator>   // std::back_inserter
#include <vector>     // std::vector
#include <iostream>
using namespace std;

int main(){
    vector<int> v1{1,2,3,4,5};
    vector<int> v2;
    // back_inserter 输出迭代器，在容器v2后面进行插入
    copy(v1.begin(),v1.end(),back_inserter(v2));
    // 输出迭代器，输出到标准输出
    copy(v2.begin(),v2.end(),ostream_iterator<int>(cout," "));
}