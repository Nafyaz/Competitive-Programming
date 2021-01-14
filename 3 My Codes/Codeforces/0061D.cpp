#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll ans, visited[100009];
vector<pair<ll, ll>> adj[100009];

ll dfs(int s, int dist)
{
    visited[s] = 1;
    ll mx = dist;

    for(auto u : adj[s])
    {
        if(!visited[u.ss])
            mx = max(mx, dfs(u.ss, dist + u.ff));
    }

    return mx;
}

int main()
{
    ll n, i, a, b, w;
    cin >> n;

    for(i = 1; i < n; i++)
    {
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});

        ans += 2*w;
    }


    cout << ans - dfs(1, 0);
}
