// https://leetcode.cn/problems/dui-cheng-de-er-cha-shu-lcof/

//请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
//
//例如，二叉树[1,2,2,3,4,4,3] 是对称的。
//
//  1
// / \
// 2  2
/// \ / \
//3 4 4 3
//但是下面这个[1,2,2,null,3,null,3] 则不是镜像对称的:
//
//  1
// / \
// 2  2
//  \  \
//   3  3
//
//示例 1：
//
//输入：root = [1,2,2,3,4,4,3]
//输出：true
//示例 2：
//
//输入：root = [1,2,2,null,3,null,3]
//输出：false

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
    bool checkSymmetricTree(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return ifEqual(root->left, root->right);
    }

private:
    bool ifEqual(TreeNode *A, TreeNode *B) {
        if (A == nullptr && B == nullptr) {
            return true;
        }
        if (A == nullptr || B == nullptr) {
            return false;
        }
        if (A->val != B->val) {
            return false;
        }
        return ifEqual(A->left, B->right) && ifEqual(A->right, B->left);
    }
};
// 核心： A左节点等于B右节点，