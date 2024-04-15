// https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/

// 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
//
//F(0) = 0，F(1) = 1
//F(n) = F(n - 1) + F(n - 2)，其中 n > 1
//给定 n ，请计算 F(n) 。
//
//答案需要取模 1e9+7(1000000007) ，如计算初始结果为：1000000008，请返回 1。

class Solution {
public:
    int fib(int n) {
        if (n == 0)return 0;
        if (n == 1)return 1;
        int ret = 0, prev = 0, curr = 1;
        for (int i = 2; i <= n; i++) {
            ret = (prev + curr) % 1000000007;
            prev = curr;
            curr = ret;
        }
        return ret;
    }
};