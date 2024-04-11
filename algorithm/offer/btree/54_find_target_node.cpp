// https://leetcode.cn/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
// 给定一棵二叉搜索树，请找出其中第k大的节点。
//
//示例 1:
//
//输入: root = [3,1,4,null,2], k = 1
//   3
//  / \
// 1   4
//  \
//  2
//输出: 4
//示例 2:
//
//输入: root = [5,3,6,2,4,null,null,1], k = 3
//       5
//      / \
//     3   6
//    / \
//   2   4
//  /
// 1
//输出: 4
//
//限制：
//
//1 ≤ k ≤ 二叉搜索树元素个数
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int findTargetNode(TreeNode *root, int cnt) {
        if (root == nullptr) {
            return 0;
        }
        this->target = cnt;
        inOrder(root);
        return ret;
    }

private:
    int target = 0, count = 0, ret = 0;
    void inOrder(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->right);
        count++;
        if (count == target) {
            ret = root->val;
            return;
        }
        inOrder(root->left);
    }
};
// 核心：这里的中序遍历是先右，再左，因为找的是第k大，不是第K小。因为中序遍历递增。
// 还有c++中匿名函数不好调用自己，就没法捕获外部变量了。因此用成员变量的方法来写。