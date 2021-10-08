#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

void solve()
{
    int n, a, i;

    priority_queue<pair<int, int>> pq;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        if(a > 0)
            pq.push({a, i});
    }

    vector<pair<int, int>> ans;
    pair<int, int> x, y;

    while(pq.size() >= 2)
    {
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();

        ans.push_back({x.ss+1, y.ss+1});

        if(x.ff >= 2)
            pq.push({x.ff-1, x.ss});
        if(y.ff >= 2)
            pq.push({y.ff-1, y.ss});
    }

    cout << ans.size() << "\n";
    for(auto u : ans)
        cout << u.ff << " " << u.ss << "\n";
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
