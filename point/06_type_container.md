# string
![string](./images/string.jpg)
[demo](./06_type_container_string.cpp)
string 支持给期待 const char* 的接口传递字符串内容（使用 c_str）

# array
![array](./images/array.svg)
[demo](./06_type_container_array.cpp)
array是c++ 11新增的序列容器，和其他容器的区别是，array的大小是固定的，无法动态扩展或者收缩。只允许访问或者替换存储的元素。
需要注意的是，这不是c数组。
# c 数组
C 数组没有 begin 和 end 成员函数（虽然可以使用全局的 begin 和 end 函数）
C 数组没有 size 成员函数（得用一些模板技巧来获取其长度）
C 数组作为参数有退化行为，传递给另外一个函数后那个函数不再能获得 C 数组的长度和结束位置,所以C的函数调用一般是 func(array, size)。所以要尽量使用array而不是c数组。

# vector
布局和array一样，但是大小可以动态变化。
![vector](./images/vector.png)
[demo](./06_type_container_vector.cpp)
# deque
双端队列，可以从头尾两端插入或者删除元素。
![deque](./images/deque.png)
不支持 data、capacity 和 reserve，因为空间不是连续的。
如果只从头、尾两个位置对 deque 进行增删操作的话，容器里的对象永远不需要移动。
由于元素部分连续，所以遍历性很高的。
如果需要一个经常在头尾增删元素的容器，那 deque 会是个合适的选择。

# list
插入效率o(1)，随机访问效率o(n)
list 不提供 data、capacity 和 reserve 成员函数（和 deque 相同）
![list](./images/list.png)
排序的话，要使用 list 的成员函数 sort，而不是 std::sort。
此外还有merge、splice、remove、reverse、unique等成员函数。

# forward_list
单向链表，只能从头部插入或者删除元素。
![forward_list](./images/forward_list.png)
为什么会需要这么一个阉割版的 list 呢？原因是，在元素大小较小的情况下，forward_list 能节约的内存是非常可观的；在列表不长的情况下，不能反向查找也不是个大问题。提高内存利用率，往往就能提高程序性能，更不用说在内存可能不足时的情况了。

# queue & stack
这两个结构c++中也提供了，就是我们常用的队列和栈。他们都是一句现有容器实现的，因此称为容器适配器（container adaptor）。简单来说就是包装了现有容器的一些接口。
他们的push和pop就是算法中的push和pop。

# less & greater

这两个是函数对象，用于比较大小。
[demo](./06_type_container_less_hash.cpp)

# priority_queue
是一个有序队列。但是他的特点是，队列中的元素是有优先级的，每次取出的元素都是优先级最高的。通过top获取最上面的元素，一般都是最大的元素(less排序)。
这也是一个容器适配器，以其他容器为基础的容器，内部有less函数。
会针对传入的less函数，对元素进行排序。也可以不传，使用默认的less函数。

# 关联容器
关联容器有 set（集合）、map（映射）、multiset（多重集）和 multimap（多重映射）。跳出 C++ 的语境，map（映射）的更常见的名字是关联数组和字典 [3]，而在 JSON 里直接被称为对象（object）。在 C++ 外这些容器常常是无序的；在 C++ 里关联容器则被认为是有序的。在go中map的打印遍历都是无序的。
