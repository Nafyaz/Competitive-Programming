#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
vector <pair<ll, ll>> adj[10009];
ll dis[10009][10009];

int main()
{
    ll i, j, k, m, u, v, w, s;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            dis[i][j] = INT_MAX;
    }

    for(i = 1; i <= n; i++)
        dis[i][i] = 0;

    for(i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
        dis[u][v] = w;
    }

    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            cout << dis[i][j] << " ";
        cout << endl;
    }
}

