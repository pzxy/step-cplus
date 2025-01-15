#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    int m, n;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        m = a;
        n = b;
        break;
    }
    int len = m * n;
    vector<int> ret(len);
    int cur = 0;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        for (int i = 0; i < b; i++) {
            ret[cur + i] = a;
        }
        cur += b;
        if (cur >= len) {
            break;
        }
    }
    while (cin >> a >> b) { // 注意 while 处理多个 case
        cout << ret[(a * n) + b] << endl;
        break;
    }
}