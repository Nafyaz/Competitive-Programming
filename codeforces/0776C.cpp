#include<bits/stdc++.h>
using namespace std;

int n;
vector <pair<int, int>> adj[505];
int dis[505];

void init()
{
    for(int i = 0; i < 505; i++)
        dis[i] = INT_MAX;
    for(int i = 0; i < 505; i++)
        adj[i].clear();
}

void dijkstra(int s)
{
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

        for(auto i : adj[node])
        {
            if(dis[i.second] > max(dis[node], i.first))
            {
                dis[i.second] = max(dis[node], i.first);
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
        init();
        scanf("%d %d", &n, &m);

        for(i = 0; i < m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }

        scanf("%d", &s);
        dijkstra(s);

        printf("Case %d:\n", ++caseno);
        for(i = 0; i < n; i++)
            dis[i] == INT_MAX? printf("Impossible\n") : printf("%d\n", dis[i]);
    }
}
