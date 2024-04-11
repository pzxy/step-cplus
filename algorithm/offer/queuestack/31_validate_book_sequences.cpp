// https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/description/
//LCR 148. 验证图书取出顺序
//已解答
//中等
//相关标签
//相关企业
//现在图书馆有一堆图书需要放入书架，并且图书馆的书架是一种特殊的数据结构，只能按照 一定 的顺序 放入 和 拿取 书籍。
//
//给定一个表示图书放入顺序的整数序列 putIn，请判断序列 takeOut 是否为按照正确的顺序拿取书籍的操作序列。你可以假设放入书架的所有书籍编号都不相同。
//
//
//
//示例 1：
//
//输入：putIn = [6,7,8,9,10,11], takeOut = [9,11,10,8,7,6]
//输出：true
//解释：我们可以按以下操作放入并拿取书籍：
//push(6), push(7), push(8), push(9), pop() -> 9,
//push(10), push(11),pop() -> 11,pop() -> 10, pop() -> 8, pop() -> 7, pop() -> 6
//示例 2：
//
//输入：putIn = [6,7,8,9,10,11], takeOut = [11,9,8,10,6,7]
//输出：false
//解释：6 不能在 7 之前取出。

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateBookSequences(vector<int> &putIn, vector<int> &takeOut) {
        if (putIn.size() != takeOut.size()) return false;
        stack<int> a;
        int j = 0;
        for (int v: putIn) {
            a.push(v);
            while (!a.empty() && a.top() == takeOut[j]) {
                a.pop();
                j++;
            }
        }
        return a.empty() && takeOut.size() == j;
    }
};
// 核心：模拟出入栈。 关键在于，循环入，每次push后，while循环从out中找当前的是不是可以pop。
