// https://leetcode.cn/problems/fu-za-lian-biao-de-fu-zhi-lcof/


//请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
// 还有一个 random 指针指向链表中的任意节点或者 null。
//示例 1：
//输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
//输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
#include <map>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr)return nullptr;
        map<Node *, Node *> m;
        m[nullptr] = nullptr;
        Node *cur = head;
        while (cur != nullptr) {
            m[cur] = new Node{cur->val};
            cur = cur->next;
        }
        cur = head;
        while (cur != nullptr) {
            m[cur]->next = m[cur->next];
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }
        return m[head];
    }
};
// 关键：
// 1. 遍历两遍，第一遍构造节点。第二遍构造顺序。
// 2. 因为第二遍要构造顺序，因此要有办法访问到第一遍的节点。这里将节点用map来存节点。k是原节点，v是新节点。