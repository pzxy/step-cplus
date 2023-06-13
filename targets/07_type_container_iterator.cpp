#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 常用迭代器
// vector::iterator 和 array::iterator 可以满足到连续迭代器。
// deque::iterator 可以满足到随机访问迭代器（记得它的内存只有部分连续）。
// list::iterator 可以满足到双向迭代器（链表不能快速跳转）。
// forward_list::iterator 可以满足到前向迭代器（单向链表不能反向遍历）。

int main()
{
    // 很常见的一个输出迭代器是 back_inserter 返回的类型 back_inserter_iterator 了；用它我们可以很方便地在容器的尾部进行插入操作。
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5, 6};
    copy(v1.begin(), v1.end(), back_inserter(v2));
    for (auto &v : v2)
    {
        // 4 5 6 1 2 3
        std::cout << v << std::endl;
    }
    // 另外一个常见的输出迭代器是 ostream_iterator，方便我们把容器内容“拷贝”到一个输出流。
    copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    // https://time.geekbang.org/column/article/176842
    // 实现一个输入行迭代器，效果是从命令行读取数据，然后输出。
    // 输入行迭代器, 从命令行读出数据，然后输出。
    // for (const string &line : istream_line_reader(std::cin))
    // {
    //     // 示例循环体中仅进行简单输出
    //     cout << line << endl;
    // }

    string line;
    for (;;)
    {
        getline(cin, line);
        if (!cin)
        {
            break;
        }
        cout << line << endl;
    }
}