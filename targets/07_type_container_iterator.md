# 迭代器

在 C++17 之前，begin 和 end 返回的类型 I 和 S 必须是相同的。从 C++17 开始，I 和 S 可以是不同的类型。这带来了更大的灵活性和更多的优化可能性。

vector::iterator 和 array::iterator 可以满足到连续迭代器。
deque::iterator 可以满足到随机访问迭代器（记得它的内存只有部分连续）。
list::iterator 可以满足到双向迭代器（链表不能快速跳转）。
forward_list::iterator 可以满足到前向迭代器（单向链表不能反向遍历）。


