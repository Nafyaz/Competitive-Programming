#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n, m, flag;
ll visited[100010];
vector <ll> adj[100010];
vector <pair<ll, ll> > color(100010);

void dfs(ll p, ll c, ll s)
{
    if(color[s].ff == color[s].ss && color[s].ff == c)
    {
        flag = 1;
        return;
    }

    if(color[s].ff == color[s].ss && color[s].ff == 0)
    {
        color[s].ff = (c + 1)%3 + 1;
        color[s].ss = (c + 2)%3 + 1;
     }
    else if(color[s].ff != color[s].ss)
    {
        if(color[s].ff == c)
            color[s].ff = 6 - color[s].ff - color[s].ss;
        else if(color[s].ss == c)
            color[s].ss = 6 - color[s].ff - color[s].ss;
    }



    visited[s] = 1;


    for(auto u : adj[s])
    {
        if(visited[u] == (c%3) + 1)
            continue;
        dfs();
    }

}

int main()
{
    ll u, v, i;
    cin >> n, m;

    for(i = 0; i <= n; i++)
        color[i].ff = color[i].ss = 0;

    for(i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(i = 1; i <= n; i++)
    {
        if(visited[i] != 0)
            continue;
        flag = 0;
        dfs(-1, 1, i);
        if(flag == 0)
            break;
    }
}
