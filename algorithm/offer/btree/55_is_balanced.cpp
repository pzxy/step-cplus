// https://leetcode.cn/problems/ping-heng-er-cha-shu-lcof/

// /**
//输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
//
//示例 1:
//
//给定二叉树 [3,9,20,null,null,15,7]
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回 true 。
//
//示例 2:
//
//给定二叉树 [1,2,2,3,3,null,null,4,4]
//
//       1
//      / \
//     2   2
//    / \
//   3   3
//  / \
// 4   4
//返回false 。
//*/
#include <algorithm>

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
    bool isBalanced(TreeNode *root) {
        if (root == nullptr) return true;
        // abs(height(root->left) - height(root->right)) <= 1 只是判断了一个节点的左右子树是否平衡。
        return abs(height(root->left) - height(root->right)) <= 1
               && isBalanced(root->left)
               && isBalanced(root->right);
    }

private:
    // 这是某节点高度的标准写法
    int height(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;
    }
};

//  核心：先写出来一个求某节点高度的方法height。
//  然后再通过 abs(height(root->left) - height(root->right)) <= 1 判断该节点的左右子树是否平衡。
//  需要注意的是，上面只是判断了一个节点的子树，还需要判断其他节点的子树。
