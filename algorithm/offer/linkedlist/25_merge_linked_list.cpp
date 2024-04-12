// https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/

//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
//
//示例1：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *trainningPlan(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr)return l2;
        if (l2 == nullptr)return l1;
        ListNode *ret = nullptr, *cur = nullptr;
        if (l1->val > l2->val) {
            cur = l2;
            l2 = l2->next;
        } else {
            cur = l1;
            l1 = l1->next;
        }
        ret = cur;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                cur->next = l2;
                break;
            }
            if (l2 == nullptr) {
                cur->next = l1;
                break;
            }
            if (l1->val > l2->val) {
                cur->next = l2;
                l2 = l2->next;
            } else {
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        return ret;
    }
};