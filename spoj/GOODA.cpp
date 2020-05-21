#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1000009;
ll n, m, s, e;
vector<ll> g[N], gr[N];
ll f[N], vis[N];
vector<ll> order, component;

void dfs1(ll v)
{
    vis[v] = 1;
    for(auto u : g[v])
    {
        if(!vis[u])
            dfs(u);
    }
    order.push_back(u);
}

void dfs2(ll v)
{
    vis[v] = 1;
    for(auto u : gr[v])
    {
        if(!vis[u])
            dfs2(u);
    }
    component.push_back(v);
}

int main()
{
    cin >> n >> m >> s >> e;
    ll i;
    for(i = 1; i <= n; i++)
        cin >> f[i];
    for(i = 1; i <= m; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    for(i = 1; i <= n; i++)
    {
        if(!vis[i])
            dfs1(i);
    }
    memset(vis, 0, sizeof vis);
    for(i = 1; i <= n; i++)
    {
        ll v = order[n-i];
        if(!vis[v])
        {
            dfs2(v);

            component.clear();
        }
    }
}
