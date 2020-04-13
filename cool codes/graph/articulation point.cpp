#include<bits/stdc++.h>
using namespace std;

int n, m, tin;
int disc[1009], low[1009], vis[1009], par[1009], AP[1009];
vector<int> adj[1009];

void init()
{
    tin = 0;
    for(i = 0; i <= n; i++)
    {
        disc[i] = -1;
        low[i] = -1;
        vis[i] = 0;
        par[i] = -1;
        Ap[i] = 0;
    }
}

dfs(int s)
{
    init();

    vis[s] = 1;
    tin++;
    disc[s] = low[s] = tin;


}

int main()
{
    int i, j, u, v;
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


}
