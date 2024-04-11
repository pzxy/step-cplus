// https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof/

//请完成一个函数，输入一个二叉树，该函数输出它的镜像。
//
//例如输入：
//
//  4
// /  \
// 2   7
/// \  / \
//1  3 6  9
//镜像输出：
//
//  4
// /  \
// 7   2
/// \  / \
//9  6 3 1

//示例 1：
//
//输入：root = [4,2,7,1,3,6,9]
//输出：[4,7,2,9,6,3,1]
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *mirrorTree(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};
// 核心：
// 左右节点交换位置