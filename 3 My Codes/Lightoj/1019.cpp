#include<bits/stdc++.h>
using namespace std;

int n;
vector <pair<int, int>> adj[110];
int dis[110];

void init()
{
    int i;
    for(i = 0; i < 110; i++)
        adj[i].clear();
    for(i = 0; i < 110; i++)
        dis[i] = INT_MAX;
}

void dijkstra(int s)
{
    pair <int, int> p;
    multiset <pair <int, int> > ms;
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
    int i, u, v, w, m, t, caseno = 0;
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

        dijkstra(1);

        printf("Case %d: ", ++caseno);
        dis[n] == INT_MAX? printf("Impossible\n") : printf("%d\n", dis[n]);
    }
}

