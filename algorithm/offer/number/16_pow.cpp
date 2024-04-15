// https://leetcode.cn/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/

// LCR 134. Pow(x, n)
//实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。

// 就是 x^9等于x^4 * x^4 * x,以此类推。
class Solution {
public:
    double myPow(double x, long long n) {
        if (n < 0) return 1.0 / myPow(x, -n);

        double ret = 1.0;
        while (n) {
            if (n & 1) ret *= x;
            x *= x;
            n >>= 1;
        }
        return ret;
    }
};
