#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second

ll n;
ll cap[109][109], par[109];
vector<ll> adj[109];

ll dfs(ll s, ll t)
{
    if(s == t)
        return INT_MAX;

    ll flow = INT_MAX;
    for(auto next : adj[s])
    {
        if(par[next] == -1 && cap[s][next])
        {
            par[next] = s;
            flow = min({flow, cap[s][next], dfs(next, t)});
        }
    }

    return flow;
}

ll maxflow(ll s, ll t)
{
    ll flow = 0, new_flow;
    memset(par, -1, sizeof par);
    par[s] = -2;
    new_flow = dfs(s, t);

    while(par[t] != -1)
    {
        flow += new_flow;

        ll cur = t;
        while(cur != s)
        {
            ll prev = par[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }

        memset(par, -1, sizeof par);
        par[s] = -2;
        new_flow = dfs(s, t);
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

