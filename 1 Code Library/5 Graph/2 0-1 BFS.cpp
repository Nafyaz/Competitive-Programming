vector<pll> adj[MAXN];
ll dist[MAXN];

void bfs01(ll cur)
{
    ll nxt, d;
    dequeu<pll> dq;
    dq.push_back({0, cur});
    dist[cur] = 0;

    while(!dq.empty())
    {
        d = dq.front().ff;
        nxt = dq.front().ss;
        dq.pop_front();

        if(dist[nxt] < d)
            continue;
        
        for(auto [nxt, d2] : adj[cur])
        {
            if(dist[nxt] == -1 || d + d2 < dist[nxt])
            {
                dist[nxt] = d + d2;

                if(d2)
                    dq.push_back({dist[nxt], nxt});
                else
                    dq.push_front({dist[nxt], nxt});
            }
        }
    }
}