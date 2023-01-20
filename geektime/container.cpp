#include <iostream>
#include <map>
#include <vector>
int main()
{

    std::vector<std::vector<int>> vv{
        {1, 1}, {2, 4}, {3, 9}};
    for (auto &v : vv)
    {
        for (auto &n : v)
        {
            printf("%d ", n);
        }
        printf("\n");
    }

    std::map<int, int> mp{
        {1, 1}, {2, 4}, {3, 9}};
    std::map<int, int>::iterator iter;
    for (iter = mp.begin(); iter != mp.end(); iter++)
    {
        printf("%d : %d\n", iter->first, iter->second);
    }
}