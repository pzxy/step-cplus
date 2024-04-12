// https://leetcode.cn/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/description/

// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。


class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node *treeToDoublyList(Node *root) {
        if (root == nullptr)return nullptr;
        build(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

private:
    Node *head, *pre;

    void build(Node *cur) {
        if (cur == nullptr)return;
        build(cur->left);
        if (pre == nullptr) {
            head = cur;
        } else {
            pre->right = cur;
            cur->left = pre;
        }
        pre = cur;
        build(cur->right);
    }
};
// 核心：中序遍历的中间输出的部分，就是当前值。然后pre是指针末尾。