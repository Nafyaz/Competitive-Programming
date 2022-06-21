#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n;
vector <pair<ll, ll>> adj[505];
ll dis[505], par[505];

void init()
{
    for(ll i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
        par[i] = -1;
    }
}

void dijkstra(ll s)
{
    init();

    set <pair<ll, ll> > q;

    dis[s] = 0;
    q.insert({0, s});

    while(!q.empty())
    {
        pair<ll, ll> p = *q.begin();
        q.erase(q.begin());

        ll node = p.ss;
        if(p.ff > dis[node])
            continue;

        for (auto u : adj[node])
        {
            ll len = u.ff;
            ll to = u.ss;
            if (dis[node] + len < dis[to])
            {
                dis[to] = dis[node] + len;
                q.insert({dis[to], to});
                par[to] = node;
            }
        }
    }
}

int main()
{
    ll i, m, s;

    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    cin >> s;
    dijkstra(s);

    for(i = 1; i <= n; i++)
        cout << i << ": " << dis[i] << endl;
}