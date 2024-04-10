// https://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/description/

//
//相关标签
//相关企业
//科技馆内有一台虚拟观景望远镜，它可以用来观测特定纬度地区的地形情况。该纬度的海拔数据记于数组 heights ，
// 其中 heights[i] 表示对应位置的海拔高度。请找出并返回望远镜视野范围 limit 内，可以观测到的最高海拔值。
//
//示例 1：
//
//输入：heights = [14,2,27,-5,28,13,39], limit = 3
//输出：[27,27,28,28,39]
//解释：
//  滑动窗口的位置                最大值
//---------------               -----
//[14 2 27] -5 28 13 39          27
//14 [2 27 -5] 28 13 39          27
//14 2 [27 -5 28] 13 39          28
//14 2 27 [-5 28 13] 39          28
//14 2 27 -5 [28 13 39]          39
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxAltitude(vector<int> &heights, int limit) {
        vector<int> ret;
        deque<int> dq;
        for (int i = 0; i < heights.size(); i++) {
            // 1. 添加, 新来的值要比队列中的小，如果大，就要删除队列后面的那个，这里前面可能有多个，所以是while循环
            while (!dq.empty() && heights[dq.back()] <= heights[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            // 2. 删除,当前超过了窗口，就删掉当前窗口前的最大值。
            if (i - dq.front() >= limit) {
                dq.pop_front();
            }
            // 3. 添加结果，不是全部添加，刚开始不满足窗口大小时候是不添加的。
            if (i + 1 >= limit) {
                ret.push_back(heights[dq.front()]);
            }
        }
        return ret;
    }
};

int main() {
    Solution s{};
    vector<int> v = {1};
    auto ret = s.maxAltitude(v, 1);
    for (auto num: ret) {
        cout << num << ",";
    }
}