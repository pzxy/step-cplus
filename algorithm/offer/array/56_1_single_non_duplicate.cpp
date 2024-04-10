// https://leetcode.cn/problems/skFtm2/description/

//LCR 070. 有序数组中的单一元素
//中等
//相关标签
//相关企业
//给定一个只包含整数的有序数组 nums ，每个元素都会出现两次，唯有一个数只会出现一次，请找出这个唯一的数字。
//
//
//
//示例 1:
//
//输入: nums = [1,1,2,3,3,4,4,8,8]
//输出: 2
//示例 2:
//
//输入: nums =  [3,3,7,7,10,11,11]
//输出: 10
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        if (nums.empty()){
            return -1;
        }
        int ret = nums[0];
        // 异或运算
        for(int i=1;i<nums.size();i++){
            ret ^= nums[i];
        }
        return ret;
    }
};