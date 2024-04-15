// https://leetcode.cn/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/

// LCR 138. 有效数字
//已解答
//中等
//相关标签
//相关企业
//有效数字（按顺序）可以分成以下几个部分：
//
//若干空格
//一个 小数 或者 整数
//（可选）一个 'e' 或 'E' ，后面跟着一个 整数
//若干空格
//小数（按顺序）可以分成以下几个部分：
//
//（可选）一个符号字符（'+' 或 '-'）
//下述格式之一：
//至少一位数字，后面跟着一个点 '.'
//至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
//一个点 '.' ，后面跟着至少一位数字
//整数（按顺序）可以分成以下几个部分：
//
//（可选）一个符号字符（'+' 或 '-'）
//至少一位数字
//部分有效数字列举如下：["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]
//
//部分无效数字列举如下：["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]
//
//给你一个字符串 s ，如果 s 是一个 有效数字 ，请返回 true 。
#include <string>

using namespace std;

//‘.’出现正确情况：只出现一次，且在e的前面
//‘e’出现正确情况：只出现一次，且出现前有数字
//‘+’‘-’出现正确情况：只能在开头和e后一位
class Solution {
public:
    bool validNumber(string s) {
        if(s.size() == 0) return false;

        //跳过首尾空格
        int left = 0, right = s.length() - 1;
        while(left <= right && s[left] == ' '){
            left++;
        }
        if(left > right) return false;
        while(left < right && s[right] == ' '){
            right--;
        }

        bool isNum = false;
        bool isDot = false;
        bool isEe = false;
        bool isSign = false;

        for(int i = left; i <= right; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                isNum = true;
            }
                // 一个'.'；e/E后面跟一个整数（不能有'.'）
            else if(s[i] == '.' && !isDot && !isEe){
                isDot = true;
            }
                // 一个'E'或'e'；前面需要出现过数字
            else if((s[i] == 'E' || s[i] == 'e') && isNum && !isEe){
                isEe = true;
                //// 避免e结尾的情况 e后面得跟一个整数
                isNum = false;
            }
                // '+''-'只能出现在开头或者'E'或'e'的后一位
            else if((s[i] == '+' || s[i] == '-') && (i == left || s[i - 1] == 'E' || s[i - 1] == 'e')){
                isSign = true;
            }
            else{
                return false;
            }
        }
        // 必须以数字结尾
        return isNum;
    }
};