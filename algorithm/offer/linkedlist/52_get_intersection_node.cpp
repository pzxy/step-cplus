// https://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
// 输入两个链表，找出它们的第一个公共节点。
//    a1->a2
//         \
//          c1->c2->c3
//         /
//b1->b2>b3
//在节点 c1 开始相交。
//     4->1
//         \
//          8->4->5
//         /
//   5->0>1
//输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
//输出：Reference of the node with value = 8
//输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。
//从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode *A = headA, *B = headB;
// 这里只所以这样是：
//    a1->a2
//         \
//          c1->c2->c3
//         /
//b1->b2>b3
// a1到c3，再从b1到b3 刚好等于 b1到c3再从a1到a2. 然后它们下一个c1就会相遇。

// 还有另外一个办法就是，先遍历一个，将值存到map中，然后遍历另外一个链表，如果map中存在，就返回这个节点。
        while (A != B) {
            A = (A != nullptr ? A->next : headB);
            B = (B != nullptr ? B->next : headA);
        }
        return A;
    }
};