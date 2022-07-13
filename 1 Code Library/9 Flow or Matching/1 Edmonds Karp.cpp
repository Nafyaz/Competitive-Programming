// Complexity O(VE^2)
ll n;
ll cap[109][109], parent[109];
bool vis[109];
vector<ll> adj[109];

ll bfs(ll s, ll t)
{
    memset(vis, 0, sizeof vis);

    ll cur, flow, new_flow;
    
    queue<pll> q;
    q.push({INT_MAX, s});
    vis[s] = 1;

    while(!q.empty())
    {
        flow = q.front().ff;
        cur = q.front().ss;
        q.pop();

        for(auto nxt : adj[cur])
        {
            if(vis[nxt] == 0 && cap[cur][nxt])
            {
                parent[nxt] = cur;
                new_flow = min(flow, cap[cur][nxt]);
                
                if(nxt == t)
                    return new_flow;

                q.push({new_flow, nxt});
                vis[nxt] = 1;
            }
        }
    }

    return 0;
}

ll maxflow(ll s, ll t)
{
    ll prev, cur;
    ll flow = 0, new_flow;

    while(new_flow = bfs(s, t))
    {
        flow += new_flow;

        for(cur = t; cur != s; cur = prev)
        {
            prev = parent[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
        }
    }

    return flow;
}

/*

memset(cap, 0, sizeof cap);

cap[a][b] += w;
cap[b][a] += w;
adj[a].pb(b);
adj[b].pb(a);

cout << maxflow(s, t);
*/