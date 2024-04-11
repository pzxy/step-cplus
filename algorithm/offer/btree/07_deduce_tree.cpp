// https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/description/

// LCR 124. 推理二叉树
//已解答
//中等
//相关标签
//相关企业
//某二叉树的先序遍历结果记录于整数数组 preorder，它的中序遍历结果记录于整数数组 inorder。请根据 preorder 和 inorder 的提示构造出这棵二叉树并返回其根节点。
//
//
//
//注意：preorder 和 inorder 中均不含重复数字。
//
//
//
//示例 1：
//
//
//
//输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//
//输出: [3,9,20,null,null,15,7]


#include <vector>

using namespace std;

//Definition for a binary tree node.
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
    TreeNode *deduceTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
// 使用 preBegin，preEnd来标记前序列的子数在原树中的下标位置。
// c++中采用下标这种方式，go中，直接通过切片的方式。类似preorder[1:k+1]这样，来截取。
private:
    TreeNode *buildTree(vector<int> &preorder, int preBegin, int preEnd, vector<int> &inorder, int inBegin, int inEnd) {
        for (int i = inBegin; i <= inEnd; i++) {
            if (inorder[i] == preorder[preBegin]) {
                int k = i - inBegin;
                return new TreeNode{
                        inorder[i],
                        buildTree(preorder, preBegin + 1, preBegin + k, inorder, inBegin, i - 1),
                        buildTree(preorder, preBegin + k + 1, preEnd, inorder, i + 1, inEnd),
                };
            }
        }
        return nullptr;
    }
};
// 核心：
// 找到根节点，然后构建。这个方式要背下来。