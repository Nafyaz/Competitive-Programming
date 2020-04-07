#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int dis[109], vis[109], n;
vector<pair<int, int> > adj[109];

void init()
{
    for(int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
        vis[i] = 0;
    }
}

void dijkstra(int s)
{
    init();
//    vis[s] = 1;
    dis[s] = 0;
    int node, w;
    pair<int, int> p;
    multiset<pair<int, int> > ms;
    ms.insert({0, s});
    while(!ms.empty())
    {
        p = *ms.begin();
        ms.erase(ms.begin());
        node = p.ss;

        for(auto u : adj[node])
        {
            if(dis[u.ss] > dis[node] + u.ff)
            {
                dis[u.ss] = dis[node] + u.ff;
                ms.insert(u);
            }
        }
    }
}

int main()
{
    int e, t, m, u, v, w;
    cin >> n >> e >> t >> m;

    while(m--)
    {
        cin >> u >> v >> w;
        adj[v].push_back({w, u});
    }

    dijkstra(e);

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(dis[i] <= t)
            ans++;
    }

    cout << ans;
}
