#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long

ll n, k, sz;
vector<ll> H[10004];
vector<pair<int, int>> adj[10004];

ll dist[10004], par[10004];


ll distCell(ll u, ll v)
{
    ll ret = abs(u/n - v/n) + abs((u%n) - (v%n));
    return ret;
}

void dijkstra(ll s)
{
    set<pair<ll, ll>> q;

    dist[s] = 0;
    q.insert({0, s});

    while(!q.empty())
    {
        pair<ll, ll> p = *q.begin();
        q.erase(q.begin());

        ll node = p.ss;
        if(p.ff > dist[node])
            continue;

        for(auto u : adj[node])
        {
            ll len = u.ff;
            ll to = u.ss;

            if(dist[node] + len < dist[to])
            {
                dist[to] = dist[node] + len;
                q.insert({dist[to], to});
                par[to] = node;
            }
        }
    }
}

int main()
{
    ll i, j, t, h;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        for(i = 1; i <= k; i++)
            H[i].clear();

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                cin >> h;
                H[h].push_back(i*n + j);

                adj[i*n+j].clear();
            }
        }
        adj[n*n].clear();
        adj[n*n+1].clear();


        for(auto u : H[1])
            adj[n*n].push_back({0, u});
        for(i = 1; i < k; i++)
        {
            for(auto u : H[i])
            {
                for(auto v : H[i+1])
                    adj[u].push_back({distCell(u, v), v});
            }
        }
        for(auto v : H[k])
            adj[v].push_back({0, n*n+1});


        sz = n*n + 2;

        for(i = 0; i < sz; i++)
        {
            dist[i] = INT_MAX;
            par[i] = -1;
        }

        dijkstra(n*n);

        cout << dist[n*n+1] << "\n";
    }
}
