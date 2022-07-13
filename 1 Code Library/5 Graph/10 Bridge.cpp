#include<bits/stdc++.h>
using namespace std;

int n, m;
bool vis[10009];
int tin[10009], low[10009], timer;
vector<int> adj[10009];
vector<int> bridge[10009];

void dfs(int v, int p = -1)
{
    vis[v] = 1;
    timer++;
    tin[v] = low[v] = timer;

    int child = 0;
    for(auto to : adj[v])
    {
        if(to == p)
            continue;
        if(!vis[to])
        {
            child++;
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] > tin[v])
            {
                bridge[v].push_back(to);
                bridge[to].push_back(v);
            }
        }
        else
            low[v] = min(low[v], tin[to]);
    }
}

void findBR()
{
    bridge.clear();
    timer = 0;
    int i;
    for(i = 1; i <= n; i++)
    {
        vis[i] = 0;
        tin[i] = -1;
        low[i] = -1;
    }

    for(i = 1; i <= n; i++)
    {
        if(!vis[i])
            dfs(i);
    }
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

    findBR();

    cout << bridge.size();
}
