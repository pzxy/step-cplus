// https://leetcode.cn/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/
// 二叉树最近公共祖先

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q)return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr && right == nullptr)return nullptr;
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        return root;// 最后这种比较难想。都不为空，刚好在root的左右。
    }
};

// 核心：这是第四种情况：root 3，p=5，q=1
//     _______3______
//   /              \
//___5__          ___1__
//      \        /      \
//      6       2       0
//            / \
//           7   4

