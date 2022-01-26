#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int color[100005];
vector<pair<int, int>> adj[100005];

void dfs(int s, int c)
{
    color[s] = c;

    for(auto u : adj[s])
    {
        if(color[u.ss] == -1)
        {
            if(u.ff%2 == 1)
                dfs(u.ss, !c);
            else
                dfs(u.ss, c);
        }
    }
}

int main()
{
    int n, i, u, v, w;

    cin >> n;

    for(i = 1; i < n; i++)
    {
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    memset(color, -1, sizeof color);
    dfs(1, 0);

    for(i = 1; i <= n; i++)
        cout << color[i] << "\n";
}
