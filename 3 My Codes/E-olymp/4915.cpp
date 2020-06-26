#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define N 150009

vector<pair<ll, ll> > adj[N];
ll n, par[N], level[N], anc[N][21], dis[N];

void dfs(ll s, ll p, ll l, ll d)
{
    dis[s] = d;
    level[s] = l;
    par[s] = p;

    for(auto u : adj[s])
    {
        if(p == u.ss)
            continue;
        dfs(u.ss, s, l+1, d+u.ff);
    }
}


ll lca_init()
{
    ll i, j;
    dfs(0, 0, 0, 0);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 21; j++)
            anc[i][j] = 0;
    }
    for(i = 0; i < n; i++)
        anc[i][0] = par[i];

    for(j = 1; (1 << j) <= n; j++)
    {
        for(i = 0; i < n; i++)
        {
            if(anc[i][j-1] != -1)
                anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
}

ll lca(ll u, ll v)
{
    if(level[u] < level[v])
        swap(u, v);
    ll i;
    for(i = log2(n) + 1; i >= 0; i--)
    {
        if(level[anc[u][i]] >= level[v])
            u = anc[u][i];
    }

    if(u == v)
        return u;

    for(i = log2(n) + 1; i >= 0; i--)
    {
        if(anc[u][i] != anc[v][i])
        {
            u = anc[u][i];
            v = anc[v][i];
        }
    }

    return par[u];
}

int main()
{
    ll i, x, m, u, v, w;
    scanf("%lld", &n);
    for(i = 1; i < n; i++)
    {
        par[i] = -1;
        scanf("%lld %lld %lld", &u, &v, &w);
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    lca_init();
    scanf("%lld", &m);
    while(m--)
    {
        scanf("%lld %lld", &u, &v);
        x = lca(u, v);
//        cout << "lca: " << x << endl;

        printf("%lld\n", dis[u] + dis[v] - 2*dis[x]);
    }
}

