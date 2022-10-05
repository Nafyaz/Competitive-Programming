int n, m;
bool vis[MAXN];
int tin[MAXN], low[MAXN], timer;
vector<int> adj[MAXN];
vector<int> bridge[MAXN];

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
