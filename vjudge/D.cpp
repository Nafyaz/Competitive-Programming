#include<bits/stdc++.h>
using namespace std;

int n, k, d[1010], dis[1010][1010], vis[1010];
vector <pair<int, int>> adj[1010];

void init(int s)
{
    for(int i = 0; i < n; i++)
        dis[s][i] = INT_MAX;
    for(int i = 0; i < n; i++)
        vis[i] = 0;
}

void dijkstra(int s)
{
    init(s);

    multiset <pair<int, int> > ms;
    pair <int, int> p;
    int node;

    dis[s][s] = 0;
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
            if(dis[s][i.second] > dis[s][node] + i.first)
            {
                dis[s][i.second] = dis[s][node] + i.first;
                ms.insert(i);
            }
        }
    }
}

int main()
{
    cout << "hi";
    int i, j, u, v, w;
    cin >> n >> k;

    for(i = 1; i <= n; i++)
        cin >> d[i];

    for(i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    for(i = 1; i <= n; i++)
        dijkstra(i);


    int totaldis[1010][1010] = {0}, sum, mnsum = INT_MAX;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            totaldis[i][j] += d[i]*dis[i][j];
        sort(totaldis[i] + 1, totaldis[i] + n + 1, greater<int>());

        for(j = k+1; j <= n; j++)
            sum += totaldis[i][j];
        mnsum = min(sum, mnsum);
    }

    cout << mnsum;
}
/*
5 3
8 5 1 8 7
1 3 8
2 3 9
3 5 7
3 4 8
*/
