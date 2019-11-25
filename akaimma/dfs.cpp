#include<bits/stdc++.h>
using namespace std;
int vis[10000];
vector <int> adj[10000];

void dfs(int u)
{
    printf("%d ", u);
    vis[u] = 1;
    int node;
    for(int i = 0; i < adj[u].size(); i++)
    {
        node = adj[u][i];
        if(vis[node] == 0)
            dfs(node);
    }
}
int main()
{
    int i, n, e, x, y;
    scanf("%d %d", &n, &e);

    for(i = 0; i < e; i++)
    {
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
}
