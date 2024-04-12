// https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
// LCR 123. 图书整理 I
//已解答
//简单
//相关标签
//相关企业
//书店店员有一张链表形式的书单，每个节点代表一本书，节点中的值表示书的编号。为更方便整理书架，店员需要将书单倒过来排列，就可以从最后一本书开始整理，逐一将书放回到书架上。请倒序返回这个书单链表。
//
//示例 1：
//
//输入：head = [3,6,4,1]
//
//输出：[1,4,6,3]
//
//提示：
//
//0 <= 链表长度 <= 10000

#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> reverseBookList(ListNode *head) {
        recur(head);
        return ret;
    }

private:
    vector<int> ret;

    void recur(ListNode *head) {
        if (head == nullptr) return;
        recur(head->next);
        ret.push_back(head->val);
    }
};

// 核心：反转打印就是先进后出，也就栈，递归的本质就是栈。这里可以用栈，也可以用递归。