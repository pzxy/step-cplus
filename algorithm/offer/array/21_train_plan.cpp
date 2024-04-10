// https://leetcode.cn/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/description/
// 奇数在前，偶数在后
/**
*
代码
测试用例
测试结果
测试结果
LCR 139. 训练计划 I
已解答
简单
相关标签
相关企业
教练使用整数数组 actions 记录一系列核心肌群训练项目编号。为增强训练趣味性，需要将所有奇数编号训练项目调整至偶数编号训练项目之前。
 请将调整后的训练项目编号以 数组 形式返回。



示例 1：

输入：actions = [1,2,3,4,5]
输出：[1,3,5,2,4]
解释：为正确答案之一
*/
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> trainingPlan(vector<int> &actions) {
        int low = 0;
        int high = actions.size() - 1;
        while (low < high) {
            while (low <high && (actions[low]&1) == 1) low++;
            while (low <high && (actions[high]&1) == 0) high--;
            swap(actions[low],actions[high]);
        }
        return actions;
    }
};
// 核心：
// i找偶数，&1=1表示奇数，奇数就+1，偶数就跳出循环。
// j找奇数，&1=0表示偶数，偶数就-1，奇数就跳出循环。
// 然后交换位置