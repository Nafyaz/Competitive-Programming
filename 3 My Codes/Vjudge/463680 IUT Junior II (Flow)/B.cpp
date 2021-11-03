#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second

ll cap[209][209], par[209];
vector<ll> adj[209];

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
        for(ll cur = t; cur != s; cur = par[cur])
        {
            ll prev = par[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
        }
    }

    return flow;
}

int main()
{
    ll T, caseno = 0, n, m, i, s, t;
    cin >> T;
    while(T--)
    {
        cin >> n;

        for(i = 0; i <= 2*n + 1; i++)
            adj[i].clear();
        memset(cap, 0, sizeof cap);

        for(i = 1; i <= n; i++)
        {
            ll c;
            cin >> c;
            adj[i].pb(i+n);
            adj[i+n].pb(i);
            cap[i][i+n] = c;
        }
        cin >> m;
        for(i = 1; i <= m; i++)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            adj[a+n].pb(b);
            adj[b].pb(a+n);
            cap[a+n][b] = c;
//            cap[b+n][a] = c;
        }

        cin >> s >> t;
        for(i = 1; i <= s; i++)
        {
            ll a;
            cin >> a;
            adj[0].pb(a);
            adj[a+n].pb(0);
            cap[0][a] = INT_MAX;
        }
        for(i = 1; i <= t; i++)
        {
            ll a;
            cin >> a;
            adj[a+n].pb(2*n + 1);
            adj[2*n + 1].pb(a);
            cap[a+n][2*n + 1] = INT_MAX;
        }

        cout << "Case " << ++caseno << ": " << maxflow(0, 2*n + 1) << endl;
    }
}
/*
1
8
2 2 2 2 2 2 2 2
9
1 2 1
2 3 1
3 4 1
1 5 1
5 4 1
5 6 1
6 7 1
7 8 1
4 8 1
1 1
1 8
*/

