// https://leetcode.cn/problems/majority-element/description/

/**
* 169. 多数元素
已解答
简单
相关标签
相关企业
给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。



示例 1：

输入：nums = [3,2,3]
输出：3
示例 2：

输入：nums = [2,2,1,1,1,2,2]
输出：2

*/
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size();
        int ret = 0, votes = 0;
        for (int i = 0; i < n; i++) {
            if (votes == 0) {
                ret = nums[i];
                votes++;
                continue;
            }
            if (nums[i] == ret) {
                votes++;
            } else {
                votes--;
            }
        }
        return ret;
    }
};
// 核心：
// 相同，得票，+1
// 不同，不得票，-1