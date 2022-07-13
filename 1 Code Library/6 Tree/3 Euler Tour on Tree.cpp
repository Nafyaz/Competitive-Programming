ll idx;
ll tour[MAXN];
vector<ll> adj[MAXN];

void createTourTree(ll node, ll p = -1)
{
    for(auto u : adj[node])
    {
        if(u != p)
            dfs(u, node);
    }

    tour[idx] = node;
    idx++;
}

idx = 0; // must before calling this function