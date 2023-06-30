#include <array>
#include <iostream>
#include <cassert>


#define ARRAY_LEN(a) \
  (sizeof(a) / sizeof((a)[0]))

void iteratorsArray()
{
    std::cout << "iteratorsArray" << std::endl;
    // 初始化
    // std::array<int, 5> arr{1, 2, 3, 4, 5};
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    for (auto &value : arr)
    {
        std::cout << value << std::endl;
    }

    // begin rbegin cbegin crbegin
    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        std::cout << *i;
    }
    std::cout << std::endl;
}

void accessArray()
{
    std::cout << "accessArray" << std::endl;
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    // at front back
    assert(arr.at(0) == 1);
    assert(arr.front() == 1);
    assert(arr.back() == 5);
    assert(arr[2] == 3);
    // arr.data() 返回指向数组首元素的指针
    assert(arr.data() == &arr[0]);
    assert(arr.data() != &arr[1]);
    assert(arr.data()[1] = 2);
}

void capacityArray()
{
    std::cout << "capacityArray" << std::endl;
    std::array<int, 10> arr = {1, 2, 3, 4, 5};
    
    assert(arr.size() == 10);
    assert(arr.max_size() == arr.max_size()); // string的max_size()是非常大的，和虚拟内存大小有关。
    assert(arr.empty() == false);
}

void modifilesArray()
{
    std::cout << "modifilesArray" << std::endl;
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 = {6, 7, 8, 9, 0};
    arr.swap(arr2);
    assert(arr.data()[0] == 6);
}

int main()
{
    iteratorsArray();
    accessArray();
    capacityArray();
    modifilesArray();
    return 0;
}