// https://leetcode.cn/problems/que-shi-de-shu-zi-lcof/description/

//LCR 173. 点名
//已解答
//简单
//相关标签
//相关企业
//某班级 n 位同学的学号为 0 ~ n-1。点名结果记录于升序数组 records。假定仅有一位同学缺席，请返回他的学号。
//
//
//
//示例 1:
//
//输入: records = [0,1,2,3,5]
//输出: 4
//示例 2:
//
//输入: records = [0, 1, 2, 3, 4, 5, 6, 8]
//输出: 7
#include <vector>

using namespace std;

class Solution {
public:
    int takeAttendance(vector<int> &records) {
        int low = 0, pivot = 0, high = records.size() -1;
        while (low <= high) {// 相等要进来吗？要进来，有单独0的情况。
            pivot = low + ((high - low) >> 1);
            if (records[pivot] == pivot) {
                low = pivot + 1;
            } else {
                high = pivot -1;// 要减去1吗？需要，如果low和high一样，中位数就一样，如果中位数还和中位值不相等，则无限进入此分支，无限循环。
            }
        }
        return low;
    }
};
// 关键：
// 1. 步的粒度是1，特别是low的粒度。这种双指针，二分的题，一定有一个粒度是1
