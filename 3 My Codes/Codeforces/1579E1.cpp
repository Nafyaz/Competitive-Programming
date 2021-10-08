#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, i, p;

    cin >> n;
    deque<int> d;

    for(i = 0; i < n; i++)
    {
        cin >> p;
        if(d.empty())
        {
            d.push_back(p);
            continue;
        }

        if(d.front() > p)
            d.push_front(p);
        else
            d.push_back(p);
    }

    for(auto u : d)
        cout << u << " ";
    cout << "\n";
}

int main()
{
    int t;

    cin >> t;

    while(t--)
    {
        solve();
    }
}
