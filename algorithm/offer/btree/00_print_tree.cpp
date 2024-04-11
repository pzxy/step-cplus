
#include <vector>
#include <iostream>

using namespace std;

//Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    // vector
    void preOrder(vector<int> &root) {

    }

    void inOrder(vector<int> &root) {

    }

    void postOrder(vector<int> &root) {

    }

    // treeNode
    void preOrder(TreeNode *root) {
        if (root == nullptr) return;
        cout << root->val << ' ';
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(TreeNode *root) {
        if (root == nullptr)return;
        inOrder(root->left);
        cout << root->val << ' ';
        inOrder(root->right);
    }

    void postOrder(TreeNode *root) {
        if (root == nullptr)return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << ' ';
    }
};


int main() {
    // build tree
    // preOrder: 0 1 3 4 2 5 6
    // inOrder: 3 1 4 0 5 2 6
    // postOrder: 3 4 1 5 6 2 0
    TreeNode root{0,
                  new TreeNode{1,
                               new TreeNode{3, nullptr, nullptr},
                               new TreeNode{4, nullptr, nullptr}},
                  new TreeNode{2,
                               new TreeNode{5, nullptr, nullptr},
                               new TreeNode{6, nullptr, nullptr}}};
    Solution s{};
    s.preOrder(&root);
    cout << endl;
    s.inOrder(&root);
    cout << endl;
    s.postOrder(&root);
    cout << endl;
}
