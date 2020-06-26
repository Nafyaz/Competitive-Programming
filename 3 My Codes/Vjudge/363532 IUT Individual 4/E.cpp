#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n, level[20009], par[20009], anc[20009][20], farleaf[20009];
vector<int> adj[20009];

pair<int, int> dfs(int node, int p, int l)
{
    par[node] = p;
    level[node] = l;

    pair<int, int> mxpii;
    mxpii.ff = l;
    mxpii.ss = node;

    for(auto u : adj[node])
    {
        if(u != p)
            mxpii = max(mxpii, dfs(u, node, l+1));
    }

    farleaf[node] = mxpii.ss;
    return mxpii;
}

void lca_init()
{
    dfs(1, 1, 0);

    int i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j < 20; j++)
            anc[i][j] = 1;
    }

    for(i = 1; i <= n; i++)
        anc[i][0] = par[i];

    for(j = 1; j < 20; j++)
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
    for(i = 19; i >= 0; i--)
    {
        if(level[anc[u][i]] >= level[anc[v][i]])
            u = anc[u][i];
    }

    if(u == v)
        return u;

    for(i = 19; i >= 0; i--)
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
    int q, i, u, v, d;
    cin >> n >> q;

    for(i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    lca_init();

    while(m--)
    {
        cin >> v >> d;
        if(level[farleaf[v]] - level[v] >= d)
        {
            u = farleaf[v];
            for(i = 19; i >= 0; i--)
            {
                if(level[anc[u][i] - level[v] >= d)
                {
                    u = anc[u][i];
                    d -= (1 << i);
                }
            }

            cout << u << endl;
            continue;
        }
        if(level[farleaf[1]] + )

    }
}
