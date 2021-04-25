#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n, m, k;
ll cap[109][109], par[109];
vector<ll> adj[109];

ll bfs(ll s, ll t)
{
    memset(par, -1, sizeof par);
    par[s] = -2;

    queue<pair<ll, ll>> q;
    q.push({s, INT_MAX});

    while(!q.empty())
    {
        ll cur = q.front().ff;
        ll flow = q.front().ss;
        q.pop();

        for(auto next : adj[cur])
        {
            if(par[next] == -1 && cap[cur][next])
            {
                par[next] = cur;
                ll new_flow = min(flow, cap[cur][next]);
                if(next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll maxflow(ll s, ll t)
{
    ll flow = 0, new_flow;

    while(new_flow = bfs(s, t))
    {
        flow += new_flow;

        ll prev, cur, len = 0;
        for(cur = t; cur != s; cur = prev)
        {
            prev = par[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;

            len++;
        }

        if(flow >= k)
            return len;
    }

    return -1;
}

int main()
{
    ll T, i, u, v;

    cin >> T;

    while(T--)
    {
        cin >> n >> m >> k;

        memset(cap, 0, sizeof cap);
        for(i = 1; i <= n; i++)
            adj[i].clear();

        while(m--)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);

            cap[u][v] = 1;
            cap[v][u] = 0;
        }

        cout << maxflow(1, n) << "\n";
    }
}
