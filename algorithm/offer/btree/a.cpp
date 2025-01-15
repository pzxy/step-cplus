// 在一个有序数组查找一个元素的上界和下界

#include <array>
using namespace std;

int main()
{
    array<int,8> a;
    int target;
    int high = -1,low = -1;
    bool flag = false;
    for (int i =0;i<a.size();i++)
    {
        if (!flag && a[i]== target){
            high = i;
            flag = true;
        }
        if (flag && a[i] != target)
        {
            low = i-1;
        }
    }
}