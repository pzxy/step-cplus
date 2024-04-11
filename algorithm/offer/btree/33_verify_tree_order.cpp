// https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/

//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
//如果是则返回true，否则返回false。
//假设输入的数组的任意两个数字都互不相同。
//
//参考以下这颗二叉搜索树：
//
//     5
//    / \
//   2   6
//  / \
// 1   3
//示例 1：
//
//输入: [1,6,3,2,5]
//输出: false
//示例 2：
//
//输入: [1,3,2,6,5]
//输出: true
//
//
//提示：
//
//数组长度 <= 1000
//
//思路：[1,3,2,6,5]，搜索树：左子树的节点都小于根结点，又子树的节点都大于根结点。
//5是根节点，找到比5大的节点6，那么数组中，6到5之前的树都是右子树。数组头到6的树都是左子树。
//然后依次递归。
#include <vector>

using namespace std;

class Solution {
public:
    bool verifyTreeOrder(vector<int> &postorder) {
        return recur(postorder, 0, postorder.size() - 1);
    }

private:
    bool recur(vector<int> &postorder, int i, int j) {
        if (i >= j)return true;
        int p = i;
        while (postorder[p] < postorder[j]) p++;
        int rightBegin = p;
        while (postorder[p] > postorder[j])p++;
        // p=jp = jp=j ： 判断 此树 是否正确。
        //recur(i,m−1)recur(i, m - 1)recur(i,m−1) ： 判断 此树的左子树 是否正确。
        //recur(m,j−1)recur(m, j - 1)recur(m,j−1) ： 判断 此树的右子树 是否正确。
        return p == j && recur(postorder, i, rightBegin - 1) && recur(postorder, rightBegin, j - 1);
    }
};
// 核心：
// 从左往右数，比root大 + 比root小 = 数组长度-1


