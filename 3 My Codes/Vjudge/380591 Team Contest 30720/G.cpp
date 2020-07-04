#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n, m, f;
vector<pair<ll, ll>> adj[109];
bool fr[109];
ll dis[109][10], vis[109];

void init()
{
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 0; j <= f; j++)
        {
            dis[i][j] = INT_MAX;
            vis[i][j] = 0;
        }
    }
}

ll dfs(int s, int picked)
{
    if(s == n && picked == f)
        return ;
    else if(s == n)
        return INT_MAX;

    ll ret = INT_MAX;
    for(auto u : adj[s])
    {
        if(u.ss != s)
            ret = min(ret, u.ff + dfs(u.ss, picked + (fr[s] == 1)));
    }

    return ret;
}

void solve()
{
    ll i;
    cin >> n >> m >> f;

    for(i = 0; i <= n; i++)
    {
        adj[i].clear();
        fr[i] = 0;
    }

    for(i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    for(i = 0; i < f; i++)
    {
        ll x;
        cin >> x;
        fr[x] = 1;
    }

    init();
    cout << dfs(1, 0) << endl;
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
        solve();
}
