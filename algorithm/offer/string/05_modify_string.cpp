// https://leetcode.cn/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
// 替换所有问号,要求替换后左右和它不相同。
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != '?') {
                continue;
            }
            if (n == 1) {
                return "a";
            }
            for (char ch = 'a'; ch <= 'c'; ++ch) {//用 a b c和替换的前后对比，一定有不同的。
                if (i - 1 >= 0 && i + 1 < n) {
                    if (s[i + 1] == ch) {
                        continue;
                    }
                    if (s[i - 1] == ch) {
                        continue;
                    }
                    s[i] = ch;
                }
                if (i == 0 && i + 1 < n) {
                    if (s[i + 1] == ch) {
                        continue;
                    }
                    s[i] = ch;
                }
                if (i == n - 1 && i - 1 >= 0){
                    if (s[i - 1] == ch) {
                        continue;
                    }
                    s[i] = ch;
                }
            }
        }
        return s;
    }
};

int main() {
    Solution s{};
    string ret = s.modifyString("a?");
    cout << ret << endl;
}