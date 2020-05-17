#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n;
vector <pair<int, int>> adj[505];
int dis[505], p[505];

void init()
{
    for(int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
        p[i] = -1;
    }
}

void dijkstra(int s)
{
    init();

    set <pair<int, int> > q;
    int node;

    dis[s] = 0;
    q.insert({0, s});

    while(!q.empty())
    {
        node = q.begin()->ss;
        q.erase(q.begin());

        for (auto u : adj[node])
        {
            int to = u.ff;
            int len = u.ss;

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
