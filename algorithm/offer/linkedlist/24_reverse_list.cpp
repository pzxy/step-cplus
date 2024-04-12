// https://leetcode.cn/problems/fan-zhuan-lian-biao-lcof/
//定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
//
//示例:
//
//输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL
//
//限制：
//
//0 <= 节点个数 <= 5000

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *trainingPlan(ListNode *head) {
        if (head == nullptr)return nullptr;
        ListNode *cur = head, *pre = nullptr;
        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

// 核心： 理清cur，pre，next的关系。next也就是cur->next，实际上就是cur pre next轮流换位。