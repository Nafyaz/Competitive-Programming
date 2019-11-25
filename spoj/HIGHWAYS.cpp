#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n, t;
vector <pair<int, int> > adj[100010];
int dis[100010];

void dijkstra(int s)
{
    int i, node;
    for(i = 0; i <= n; i++)
        dis[i] = INT_MAX;

    multiset <pair<int, int> > ms;
    pair <int, int> p;
    dis[s] = 0;
    ms.insert({0, s});

    while(!ms.empty())
    {
        p = *ms.begin();
        ms.erase(ms.begin());
        node = p.ss;
        for(auto p : adj[node])
        {
            if(dis[p.ss] > dis[node] + p.ff)
            {
                ms.insert(p);
                dis[p.ss] = dis[node] + p.ff;
            }
        }
    }
}

int main()
{
    int T, m, s, u, v, w;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d %d", &n, &m, &s, &t);
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
        dijkstra(s);

        dis[t] == INT_MAX? printf("NONE\n") : printf("%d\n", dis[t]);
    }
}

