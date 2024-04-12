// https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/
// LCR 136. 删除链表的节点
//已解答
//简单
//相关标签
//相关企业
//给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
//
//返回删除后的链表的头节点。
//
//示例 1:
//
//输入: head = [4,5,1,9], val = 5
//输出: [4,1,9]
//解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
//示例 2:
//
//输入: head = [4,5,1,9], val = 1
//输出: [4,5,9]
//解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *deleteNode(ListNode *head, int val) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->val == val) {
            return head->next;
        }
        ListNode *ret = head;
        while (head->next != nullptr) {
            if (head->next->val == val) {
                head->next = head->next->next;
                break;
            }
            head = head->next;
        }
        return ret;
    }
};

// 核心： 这种链表的拼接，关键是要存起来当前节点。这样别的节点才能拼接到当前节点上