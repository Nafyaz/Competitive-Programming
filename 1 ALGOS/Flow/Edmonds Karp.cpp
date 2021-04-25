#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second

ll n;
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
                if (next == t)
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
    ll T, i, s, t, c, caseno = 0;
    cin >> T;
    while(T--)
    {
        cin >> n >> s >> t >> c;
        memset(cap, 0, sizeof cap);
        for(i = 0; i < n; i++)
            adj[i].clear();

        while(c--)
        {
            ll a, b, w;
            cin >> a >> b >> w;
            cap[a][b] += w;
            cap[b][a] += w;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        cout << "Case " << ++caseno << ": " << maxflow(s, t) << endl;
    }
}
