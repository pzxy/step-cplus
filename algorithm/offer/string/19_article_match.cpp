// https://leetcode.cn/problems/zheng-ze-biao-da-shi-pi-pei-lcof/

// LCR 137. 模糊搜索验证
//已解答
//困难
//相关标签
//相关企业
//请设计一个程序来支持用户在文本编辑器中的模糊搜索功能。用户输入内容中可能使用到如下两种通配符：
//
//'.' 匹配任意单个字符。
//'*' 匹配零个或多个前面的那一个元素。
//请返回用户输入内容 input 所有字符是否可以匹配原文字符串 article。

// 示例 1:
//
//输入: article = "aa", input = "a"
//输出: false
//解释: "a" 无法匹配 "aa" 整个字符串。
//示例 2:
//
//输入: article = "aa", input = "a*"
//输出: true
//解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
//示例 3:
//
//输入: article = "ab", input = ".*"
//输出: true
//解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool articleMatch(string s, string p) {
        if (s.size() == 0 && p.size() == 0) {
            return true;
        }
        if (s.size() != 0 && p.size() == 0) {
            return false;
        }
        // s.size() ==0 && p.size() !=0; 这种情况是有两种可能的，就是 p为 .* 或者别的，因此不能直接判断true或者false
        bool first = 0;
        if (s.size() > 0 && (s[0] == p[0] || p[0] == '.')) {
            first = true;
        }
        if (p.size() > 1 && p[1] == '*') {
            // 第一个没匹配上，可能是 s已经不存在了，是空的。或者就是没匹配上。
            // 有可能s是空的，因为p=a*的话，实际上也是可以和空匹配的，a可以为0个的。
            return (first && articleMatch(s.substr(1), p)) || articleMatch(s, p.substr(2));
        }
        return first && articleMatch(s.substr(1), p.substr(1));
    }
};

int main() {
    Solution solution{};
    string s = "aa", p = ".*c";
    bool ret = solution.articleMatch(s, p);
    cout << ret << endl;
}