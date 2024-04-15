// https://leetcode.cn/problems/wtcaE1/
// 最长不重复子串
// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长连续子字符串 的长度。
//示例 1:
//
//输入: s = "abcabcbb"
//输出: 3
//解释: 因为无重复字符的最长子字符串是 "abc"，所以其长度为 3。
//示例 2:
//
//输入: s = "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子字符串是 "b"，所以其长度为 1。
//示例 3:
//
//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
//示例 4:
//
//输入: s = ""
//输出: 0
#include <string>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) {
            return s.length();
        }
        int max_len = 1;
        string ret;
        set<char> cs;
        cs.insert(s[0]);

        int left = 0, right = 1;
        while (left < s.size()) {
            while (right < s.size()) {
                if (cs.find(s[right]) == cs.end()) {
                    cs.insert(s[right]);
                    max_len = max(right - left + 1, max_len);
                    right++;
                } else {
                    break;
                }
            }
            cs.erase(s[left]);
            left++;
        }
        return max_len;
    }
};

int main() {
    Solution solution{};
    string s = "abcabcbb";
    int ret = solution.lengthOfLongestSubstring(s);
    cout << ret << endl;
}