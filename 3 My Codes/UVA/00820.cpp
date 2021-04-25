#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n;
ll cap[109][109], par[109];
vector<ll> adj[109];
ll mat[109][109];

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

        ll prev, cur;

        for(cur = t; cur != s; cur = prev)
        {
            prev = par[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
        }
    }

    return flow;
}

int main()
{
//    freopen("out.txt", "w", stdout);
    ll caseno = 0, s, t, c, i, u, v, w;

    while(1)
    {
        cin >> n;

        if(!n)
            break;

        for(i = 0; i <= n; i++)
            adj[i].clear();
        memset(mat, 0, sizeof mat);
        memset(cap, 0, sizeof cap);

        cin >> s >> t >> c;

        while(c--)
        {
            cin >> u >> v >> w;
            cap[u][v] += w;
            cap[v][u] += w;

            if(!mat[u][v])
            {
                mat[u][v] = mat[v][u] = 1;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        cout << "Network " << ++caseno << "\n";
        cout << "The bandwidth is " << maxflow(s, t) << ".\n\n";
    }
}
