#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> adj[200005];
ll color[200005];
bool toCycle[200005];

bool dfs(ll i)
{
    color[i] = 1;

    bool ret = 0;

    for(auto u : adj[i])
    {
        if(color[u] == 1)
        {
            toCycle[u] = 1;
            ret = 1;
        }
        else if(color[u] == 0)
            ret |= dfs(u);
        else if(color[u] == 2 && toCycle[u])
            ret = 1;
    }

    color[i] = 2;
    return toCycle[i] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, a, b, i;

    cin >> n >> m;

    for(i = 1; i <= m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(i = 1; i <= n; i++)
    {
        if(color[i] == 0)
            dfs(i);
    }

    ll ans = 0;
    for(i = 1; i <= n; i++)
        ans += toCycle[i];

    cout << ans;
}
/*
5 5
2 1
3 2
4 3
2 4
5 4
*/
