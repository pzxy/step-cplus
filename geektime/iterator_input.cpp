#include <string>
#include <iostream>
#include <iterator>
#include <istream>
using namespace std;
int main()
{

    string is; 
    for (const string &line :
         istream_line_reader(is))
    {
        // 示例循环体中仅进行简单输出
        cout << line << endl;
    }
}