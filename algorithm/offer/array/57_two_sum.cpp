// https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/
//LCR 179. 查找总价格为目标值的两个商品
//已解答
//简单
//相关标签
//相关企业
//购物车内的商品价格按照升序记录于数组 price。请在购物车中找到两个商品的价格总和刚好是 target。若存在多种情况，返回任一结果即可。
//
//示例 1：
//
//输入：price = [3, 9, 12, 15], target = 18
//输出：[3,15] 或者 [15,3]
//示例 2：
//
//输入：price = [8, 21, 27, 34, 52, 66], target = 61
//输出：[27,34] 或者 [34,27]
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &price, int target) {
        int low = 0, high = price.size() - 1;
        while (low < high) {
            if (price[low] + price[high] == target) {
                return {price[low], price[high]};
            } else if (price[low] + price[high] > target) {
                high--;
            } else {
                low++;
            }
        }
        return {};
    }
};
// 核心：
// 有序数组，可以用双指针。
// 如果a[i]+a[j]>target;则j--,小于则i++，想等就返回。