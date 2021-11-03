#include<bits/stdc++.h>
using namespace std;

int n, m;//left group size n. right group size n.
vector<int> adj[102];
vector<int> mt;
bool[102] vis;

bool try_kuhn(int v)
{
    if (vis[v])
        return false;
    vis[v] = true;
    for (int to : adj[v])
    {
        if (mt[to] == -1 || try_kuhn(mt[to]))
        {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main()
{
    int i, u, v, edges;

    cin >> n >> m >> edges;

    for(i = 1; i <= n; i++)
        adj[i].clear();

    for(i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    mt.assign(m, -1);
    for(i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof vis);
        try_kuhn(i);
    }

    for(i = 1; i <= m; i++)
    {
        if(mt[i] != -1)
            cout << mt[i] << " " << i;
    }
}
