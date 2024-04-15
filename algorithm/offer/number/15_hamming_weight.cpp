// https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/

// 十进制转二进制，计算二进制数中有多少1
//输入：n = 11 (控制台输入 00000000000000000000000000001011)
//输出：3
//解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。

#include <cstdint>
#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t ret = 0;
        while (n != 0) {
            ret += n & 1;
            n >>= 1;
        }
        return ret;
    }
};

int main() {
    Solution solution{};
    int32_t s = 4294967293;
    int ret = solution.hammingWeight(s);
    cout << ret << endl;
}