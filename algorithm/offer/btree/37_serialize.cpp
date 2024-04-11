//https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/description/

//序列化是将一个数据结构或者对象转换为连续的比特位的操作，
//进而可以将转换后的数据存储在一个文件或者内存中，
//同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
//
//请设计一个算法来实现二叉树的序列化与反序列化。
//这里不限定你的序列 / 反序列化算法执行逻辑，
//你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
//
//示例:
//
//你可以将以下二叉树：
//
//    1
//   / \
//  2   3
//     / \
//    4   5
//
//序列化为 "[1,2,3,null,null,4,5]"
//提示:这与 LeetCode 目前使用的方式一致，详情请参阅LeetCode 序列化二叉树的格式。
//你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
//
//说明:不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的
#include <string>
#include <queue>
#include <iostream>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr) {
            return "[]";
        }
        string ret = "[";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *r = q.front();
            q.pop();
            if (r == nullptr) {
                ret += "null,";
            } else {
                ret += to_string(r->val) + ",";
                q.push(r->left);
                q.push(r->right);
            }
        }
        ret.pop_back();
        ret += "]";
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.empty() || data == "[]") {
            return nullptr;
        }
        string s = data.substr(1, data.size() - 2);
        stringstream ss{s};
        string item;
        vector<string> vals;
        while (getline(ss, item, ',')) {
            vals.push_back(item);
        }

        TreeNode *root = new TreeNode(stoi(vals[0]));
        int i = 1;
        queue<TreeNode *> q{};
        q.push(root);
        while (!q.empty()) {
            TreeNode *n = q.front();
            q.pop();
            if (vals[i] != "null") {
                n->left = new TreeNode(stoi(vals[i]));
                q.push(n->left);
            }
            i++;
            if (vals[i] != "null") {
                n->right = new TreeNode(stoi(vals[i]));
                q.push(n->right);
            }
            i++;
        }
        return root;
    }
};

int main() {
    TreeNode root{1,
                  new TreeNode{2,
                               nullptr,
                               nullptr},
                  new TreeNode{3,
                               new TreeNode{4, nullptr, nullptr},
                               new TreeNode{5, nullptr, nullptr}}};
    Codec s;
    string ret = s.serialize(&root);
    cout << ret << endl;
}

// 核心：和按层打印类似，然后逐级添加。上面的结果序列化出来实际上是：[1,2,3,null,null,4,5,null,null,null,null] 如此。
//