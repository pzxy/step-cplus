// https://leetcode.cn/problems/permutation-i-lcci/description/

// 无重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合，字符串每个字符均不相同。
//
//示例1:
//
// 输入：S = "qwe"
// 输出：["qwe", "qew", "wqe", "weq", "ewq", "eqw"]
//示例2:
//
// 输入：S = "ab"
// 输出：["ab", "ba"]
//提示:
//
//字符都是英文字母。
//字符串长度在[1, 9]之间。
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 若字符串长度为n，将第一个字母分别与后面每一个字母进行交换，生成n种不同的全排列；
// 再用第二个元素与后面每一个元素进行交换，生成n - 1种不同的全排列……
class Solution {
public:
    vector<string> permutation(string S) {
        vector<string> ret{};
        ret.push_back(S);
        int cur = 0;
        while (cur < S.size()) {
            int retLen = ret.size();// for循环中的。会修改ret，因此这里要记录一下长度。
            for (int j = 0; j < retLen; j++) {
                for (int i = cur + 1; i < S.size(); i++) {
                    string tmp = ret[j];
                    swap(tmp[cur], tmp[i]);
                    ret.push_back(tmp);
                }
            }
            cur++;
        }
        return ret;
    }
};

int main() {
    Solution solution{};
    string S = "qwe";
    vector<string> ret = solution.permutation(S);
    for (const string &s: ret) {
        cout << s << endl;
    }
}