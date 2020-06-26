#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

vector<pair<int, int>> adj[510];
int dis[510];


void dijkstra(int s)
{
    for(int i = 0; i < 510; i++)
        dis[i] = INT_MAX;
    dis[s] = 0;

    multiset<pair<int, int>> ms;
    pair<int, int> p;
    ms.insert({0, s});

    while(!ms.empty())
    {
        p = *ms.begin();
        ms.erase(ms.begin());

        for(auto i : adj[p.ss])
        {
            if(dis[i.ss] > dis[p.ss] + i.ff)
            {
                dis[i.ss] = dis[p.ss] + i.ff;
                ms.insert(i);
            }
        }
    }
}

int main()
{
    int e, u, v, w;
    scanf("%d", &e);
    while(e--)
    {
         scanf("%d %d %d", &u, &v, &w);
         adj[u].push_back({w, v});
         adj[v].push_back({w, u});
    }
    int s, t, q;
    scanf("%d %d", &s, &q);

    dijkstra(s);

    while(q--)
    {
        scanf("%d", &t);
        dis[t] == INT_MAX? printf("NO PATH\n") : printf("%d\n", dis[t]);
    }

}

