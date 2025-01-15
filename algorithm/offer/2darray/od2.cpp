#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// ABC<c89%000<
// ABc89%00,true
// length >= 8
// 大写
// 小写
// 数字
// 除大小写数字空格外字符。
int main() {
    string s;
    cin >> s;
    int left = 0, right = s.size() - 1;
    string ret;
    bool ifOk = true;
    bool ifFoundLower = false;
    bool ifFoundUpper = false;
    bool ifFoundDigit = false;
    bool ifFoundSpecial = false;
    // 去掉<
    while (right >= 0) {
        int n = 0;
        if (s[right] == '<') {
            // <<<
            n += 2;
            int tmp = right - 1;
            while (tmp >= 0) {
                if (s[tmp] == '<') {
                    n += 2;
                    tmp -= 1;
                } else {
                    break;
                }
            }
        }
        right -= n;
        if (right < 0) {
            break;
        }
        // check

        if (isdigit(s[right])) {
            ifFoundDigit = true;
        } else if (isupper(s[right])) {
            ifFoundUpper = true;
        } else if (islower(s[right])) {
            ifFoundLower = true;
        } else if (s[right] != ' ') {
            ifFoundSpecial = true;
        }

        ret = s[right] + ret;
        right--;
    }
    // check
    if (ret.size() < 8) {
        ifOk = false;
    }
    if (ifOk) {
        if (ifFoundLower && ifFoundDigit && ifFoundUpper && ifFoundSpecial) {
            ifOk = true;
        } else {
            ifOk = false;
        }
    }
    string ok;
    if (ifOk) {
        ok = "true";
    } else {
        ok = "false";
    }
    cout << ret + ',' << ok << endl;
}
// 64 位输出请用 printf("%lld")