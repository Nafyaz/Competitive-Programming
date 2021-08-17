#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;

    q.push(1);
    q.push(5);
    q.push(7);
    q.push(0);
    q.push(2);

//    for(auto u : q)
//        cout << u << " ";
//    cout << "\n";

    cout << q.front() << "\n";

    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";

    cout << q.size();
}
