#include <iostream>
#include <vector>
using namespace std;
int main() {
    int num = 256;
    std::vector<uint8_t> b(32,0);
    for (int i=0;i<4;i++){
        b[31-i] = (num >> (i * 8)) & 0xFF;
    }
     for (int i = 0; i < b.size(); i++) {
        cout << (int)b[i] << " ";
    }
    cout << endl;
    return 0;
}