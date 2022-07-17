// Important Note: parent of 1 is 1
int n;
vector<int> adj[MAXN];
int parent[MAXN], level[MAXN], anc[MAXN][21];

void dfs(int cur, int p, int l)
{
    parent[cur] = p;
    level[cur] = l;

    for(auto nxt : adj[cur])
    {
        if(nxt != parent[cur])
            dfs(nxt, cur, l+1);
    }
}

void LCA_init()
{
    dfs(1, 1, 0);

    int i, j;
    for(i = 1; i <= n; i++)
        anc[i][0] = parent[i];

    for(j = 1; j < 21; j++)
    {
        for(i = 1; i <= n; i++)
            anc[i][j] = anc[anc[i][j-1]][j-1];
    }
}

int getLCA(int u, int v)
{
    if(level[u] < level[v])
        swap(u, v);

    int i;
    for(i = 20; i >= 0; i--) 
    {
        if(level[anc[u][i]] >= level[v])
            u = anc[u][i];
    }

    if(u == v)
        return u;

    for(i = 20; i >= 0; i--)
    {
        if(anc[u][i] != anc[v][i])
        {
            u = anc[u][i];
            v = anc[v][i];
        }
    }

    return parent[u];
}

// LCA_init()
// cout << getLCA(5, 8) << "\n";