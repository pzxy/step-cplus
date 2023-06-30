#include <iostream>
#include <queue>
#include <vector>
#include <memory>
#include <functional>

using namespace std;
int main()
{
    priority_queue<int> q;
    q.push(2);
    q.push(7);
    q.push(4);
    q.push(5);
    q.push(1);
    while (!q.empty())
    {
        // 输出是 7 5 4 2 1 ，是有顺序的。
        cout << q.top() << endl;
        q.pop();
    }
    // priority_queue<
    //     pair<int, int>,
    //     vector<pair<int, int>>,
    //     greater<pair<int, int>>>
    //     q2;
    // q2.push({1, 1});
    // q2.push({2, 2});
    // q2.push({0, 3});
    // q2.push({9, 4});
    // while (!q2.empty())
    // {
    //     cout << q2.top() << endl;
    //     q2.pop();
    // }
}