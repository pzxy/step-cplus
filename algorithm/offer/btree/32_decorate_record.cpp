// https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/

// LCR 149. 彩灯装饰记录 I
//已解答
//中等
//相关标签
//相关企业
// 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
//
//例如:
//给定二叉树:[3,9,20,null,null,15,7],
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回：
//
//[3,9,20,15,7]


#include <vector>
#include <queue>

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
    vector<int> decorateRecord(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> ret;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *head = q.front();
            ret.emplace_back(head->val);
            q.pop();

            if (head->left != nullptr)q.push(head->left);
            if (head->right != nullptr) q.push(head->right);
        }
        return ret;
    }
};
// 队列，层遍历