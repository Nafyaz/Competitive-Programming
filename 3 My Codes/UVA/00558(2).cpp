#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n, m;

vector<pair<ll, pair<ll, ll>>> edges;
ll dist[1009];

ll func()
{
    ll flag = 0;
    for(auto e : edges)
    {
        if(dist[e.ss.ff] + e.ff < dist[e.ss.ss])
        {
            flag = 1;
            dist[e.ss.ss] = dist[e.ss.ff] + e.ff;
        }
    }


    return flag;
}

int main()
{
    ll t, i, u, v, w;

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        edges.clear();
        for(i = 0; i < n; i++)
            dist[i] = INT_MAX;

        for(i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            edges.push_back({w, {u, v}});
        }

        for(i = 1; i < n; i++)
            func();

        cout << (func()? "possible" : "not possible") << "\n";
    }
}
