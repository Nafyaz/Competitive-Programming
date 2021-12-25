#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[200005];
bool vis[200005];

bool dfs(int node)
{
    vis[node] = 1;

    bool ret = 1;

    for(auto u : adj[node])
    {
        if(!vis[u])
            ret = min(ret, dfs(u));
    }

    return min(ret, adj[node].size() == 2);
}

int main()
{
    int u, v, i, ans = 0;
    cin >> n >> m;

    while(m--)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(i = 1; i <= n; i++)
    {
        if(!vis[i])
            ans += dfs(i);
    }

    cout << ans;
}
