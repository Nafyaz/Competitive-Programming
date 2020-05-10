#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[400009];
int parent[400009], level[400009], anc[400009][21];

void dfs(int node, int pr, int l)
{
    parent[node] = pr;
    level[node] = l;

    for(auto u : adj[node])
    {
        if(u != parent[node])
            dfs(u, node, l+1);
    }
}

void lca_init()
{
    dfs(1, 1, 0);

    int i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j <= 20; j++)
            anc[i][j] = 1;
    }
//    cout << anc[7][4] << "lol" << endl;
    for(i = 1; i <= n; i++)
        anc[i][0] = parent[i];

    for(j = 1; (1<<j) <= n; j++)
    {
        for(i = 1; i <= n; i++)
            anc[i][j] = anc[anc[i][j-1]][j-1];
    }
}

int lca(int u, int v)
{
    if(level[u] < level[v])
        swap(u, v);

    int i;
    for(i = log2(n) + 1; i >= 0; i--)
    {
        if(level[anc[u][i]] >= level[v])
        {
            u = anc[u][i];
        }
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

    return parent[u];
}

int main()
{
    int i, u, v;
    cin >> n;

    for(i = 1; i <= n-1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    lca();
    int q;
    cin >> q;
    while(q--)
    {
        cin >> u >> v;
//        cout << level[u] << " " << level[v] << endl;
//        cout << anc[7][0] << endl;
        cout << query(u, v) << endl;
    }
}
/*
10
1 3
1 7
3 2
3 10
2 6
5 7
8 5
5 9
7 4
1
7 1
*/
