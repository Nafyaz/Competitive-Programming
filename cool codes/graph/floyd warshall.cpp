#include<bits/stdc++.h>
using namespace std;

int n;
vector <pair<int, int>> adj[505];
int dis[505];



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
        init();
        dijkstra(s);

        for(i = 0; i < n; i++)
            printf("%d: %d\n", i, dis[i]);
    }
}
