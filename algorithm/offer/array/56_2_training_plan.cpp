// https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/

//LCR 178. 训练计划 VI
//已解答
//中等
//相关标签
//相关企业
//教学过程中，教练示范一次，学员跟做三次。该过程被混乱剪辑后，记录于数组 actions，其中 actions[i] 表示做出该动作的人员编号。请返回教练的编号。
//
//
//
//示例 1：
//
//输入：actions = [5, 7, 5, 5]
//输出：7
//示例 2：
//
//输入：actions = [12, 1, 6, 12, 6, 12, 6]
//输出：1
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trainingPlan(vector<int> &actions) {
        // 1. 排序
        sort(actions.begin(), actions.end());
        // 2. 3倍跳跃，不相等，返回前面的
        for (int i = 0; i < actions.size() - 2; i += 3) {
            if (actions[i] != actions[i + 2])return actions[i];
        }
        return actions.back();
    }
};


int main() {
    Solution s{};
    vector<int> actions{12, 1, 6, 12, 6, 12, 6};
    int ret = s.trainingPlan(actions);
    cout << ret << endl;
}