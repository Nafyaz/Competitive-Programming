#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

ll n, m, a, b, vis[200009][2];
vector<ll> adj[200009];

void init()
{
    ll i;
    for(i = 1; i <= n; i++)
    {
        adj[i].clear();
        vis[i][0] = 0;
        vis[i][1] = 0;
    }
}

void dfs(ll s, ll p)
{
    vis[s][p == b] = 1;
    for(auto u : adj[s])
    {
        if(!vis[u][p == b] && u != (a+b-p))
            dfs(u, p);
    }
}

int main()
{
    ll t, i, u, v;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> a >> b;
        init();
        for(i = 0; i < m; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(a, a);
        dfs(b, b);

        ll acount = 0, bcount = 0;
        for(i = 1; i <= n; i++)
        {
            if(vis[i][0] && !vis[i][1] && i != a)
                acount++;
            if(!vis[i][0] && vis[i][1] && i != b)
                bcount++;
        }

        cout << acount*bcount << endl;
    }
}
