// https://leetcode.cn/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/


// LCR 162. 数字 1 的个数 （困难）
//给定一个整数 num，计算所有小于等于 num 的非负整数中数字 1 出现的个数。
//示例 1：
//输入：num = 0
//输出：0

//示例 2：
//输入：num = 13
//输出：6
class Solution {
public:
    int digitOneInNumber(int num) {
        long long res=0;
        long long bit=1;
        while(bit<=num){
            long long cur=(num/bit)%10;
            long long low=num%bit;
            long long high=num/bit/10;
            if(cur>1){
                res+=(high+1)*bit;
            }else if(cur==1){
                res+=(high*bit)+low+1;
            }else if(cur==0){
                res+=high*bit;
            }
            bit=bit*10;
        }
        return res;
    }
};