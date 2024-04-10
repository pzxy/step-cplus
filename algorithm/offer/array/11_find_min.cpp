
// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/

/**

153. 寻找旋转排序数组中的最小值

已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。



示例 1：

输入：nums = [3,4,5,1,2]
输出：1
解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。
示例 2：

输入：nums = [4,5,6,7,0,1,2]
输出：0
解释：原数组为 [0,1,2,4,5,6,7] ，旋转 3 次得到输入数组。
示例 3：

输入：nums = [11,13,15,17]
输出：11
解释：原数组为 [11,13,15,17] ，旋转 4 次得到输入数组。
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int findMin(vector<int> &nums) {
        int low = 0;
        int high = int(nums.size() - 1);
        int pivot;
        while (low < high) {
            pivot = low + ((high - low) >> 1);
            if (nums[pivot] < nums[high]) {
                high = pivot;
            } else {
                low += 1;
            }
        }
        return nums[low];
    }
};

// 关键low和high要一个一个移动,low+1，而high = 中位数，而不是中位数-1

int main() {
    vector<int> nums{4, 5, 6, 7, 8, 9, 2, 3};
    int ret = Solution::findMin(nums);
    cout << ret << endl;
}