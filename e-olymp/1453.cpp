#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n;
vector <pair<ll, ll>> adj[109];
ll dis[109], p[109];

void init()
{
    for(ll i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
        p[i] = -1;
    }
}

void dijkstra(ll s)
{
    init();

    set <pair<ll, ll> > q;
    ll node;

    dis[s] = 0;
    q.insert({0, s});

    while(!q.empty())
    {
        node = q.begin()->ss;
        q.erase(q.begin());

        for (auto u : adj[node])
        {
            ll len = u.ff;
            ll to = u.ss;
            if (dis[node] + len < dis[to])
            {
                q.erase({dis[to], to});
                dis[to] = dis[node] + len;
                q.insert({dis[to], to});
                p[to] = node;
            }
        }
    }
}

int main()
{
    ll i, m;

    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    dijkstra(1);

    for(i = 1; i <= n; i++)
        cout << (dis[i] == INT_MAX? 30000 : dis[i]) << " ";
}
