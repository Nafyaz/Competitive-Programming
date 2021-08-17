#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>,greater<int>> pq;

//
    pq.push(1);
    pq.push(7);
    pq.push(10);
    pq.push(0);
    pq.push(-10);
//
    cout << pq.top() << "\n";
//
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}
