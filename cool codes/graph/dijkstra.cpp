#include<bits/stdc++.h>
using namespace std;

int n;
vector <pair<int, int>> adj[505];
int dis[505], vis[505];

void init()
{
    for(int i = 0; i < n; i++)
        dis[i] = INT_MAX;
    for(int i = 0; i < n; i++)
        vis[i] = 0;
}

void dijkstra(int s)
{
    init();

    multiset <pair<int, int> > ms;
    pair <int, int> p;
    int node;

    dis[s] = 0;
    ms.insert({0, s});

    while(!ms.empty())
    {
        p = *ms.begin();
        ms.erase(ms.begin());

        node = p.second;

        if(vis[node])
            continue;
        vis[node] = 1;

        for(auto i : adj[node])
        {
            if(dis[i.second] > dis[node] + i.first)
            {
                dis[i.second] = dis[node] + i.first;
                ms.insert(i);
            }
        }
    }
}

int main()
{
    int t, caseno = 0, i, m, u, v, w, s;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }

        scanf("%d", &s);
        dijkstra(s);

        for(i = 0; i < n; i++)
            printf("%d: %d\n", i, dis[i]);
    }
}
