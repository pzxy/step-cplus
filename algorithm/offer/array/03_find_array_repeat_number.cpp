// https://leetcode.cn/problems/find-all-duplicates-in-an-array/description/
/**
 * 给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 一次 或 两次 。
 * 请你找出所有出现 两次 的整数，并以数组形式返回。

你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。



示例 1：

输入：nums = [4,3,2,7,8,2,3,1]
输出：[2,3]
示例 2：

输入：nums = [1,1,2]
输出：[1]
示例 3：

输入：nums = [1]
输出：[]
 */
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] != nums[nums[i] - 1]) {// 因为有重复，所以肯定有相等的，通过值不相等，归位
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (i != nums[i]-1) {// 通过下标和值不想等，挑选
                ret.emplace_back(nums[i]);
            }
        }
        return ret;
    }
};