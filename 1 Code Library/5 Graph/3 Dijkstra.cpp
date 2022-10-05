LL n;
vector <pLL> adj[MAXN];
LL dis[MAXN], par[MAXN];

void dijkstra(LL s)
{
    for(LL i = 1; i <= n; i++)
    {
        dis[i] = INF;
        par[i] = -1;
    }

    set<pLL> q;

    dis[s] = 0;
    q.insert({0, s});

    while(!q.empty())
    {
        pLL p = *q.begin();
        q.erase(q.begin());

        LL node = p.ss;
        if(p.ff > dis[node])
            continue;

        for (auto u : adj[node])
        {
            LL len = u.ff;
            LL to = u.ss;
            if (dis[node] + len < dis[to])
            {
                dis[to] = dis[node] + len;
                q.insert({dis[to], to});
                par[to] = node;
            }
        }
    }
}
