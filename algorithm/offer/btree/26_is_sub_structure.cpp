// https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/description/
//LCR 143. 子结构判断
//已解答
//中等
//相关标签
//相关企业
//给定两棵二叉树 tree1 和 tree2，判断 tree2 是否以 tree1 的某个节点为根的子树具有 相同的结构和节点值 。
//注意，空树 不会是以 tree1 的某个节点为根的子树具有 相同的结构和节点值 。

//例如:
//给定的树 A:
//
//   3
//  / \
// 4  5
// / \
//1  2
//给定的树 B：
//  4
// /
//1
//返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。
//
//示例 1：
//
//输入：A = [1,2,3], B = [3,1]
//输出：false
//示例 2：
//
//输入：A = [3,4,5,1,2], B = [4,1]
//输出：true



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (A == nullptr || B == nullptr) {
            return false;
        }
        return ifEqual(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

private:
    bool ifEqual(TreeNode *A, TreeNode *B) {
        if (B == nullptr) {
            return true;
        }
        if (A == nullptr || A->val != B->val) {
            return false;
        }
        return ifEqual(A->left, B->left) && ifEqual(A->right, B->right);
    }
};
// 核心：
// 1. 找到根节点，开始对比
