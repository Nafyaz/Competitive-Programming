#include<bits/stdc++.h>
using namespace std;

bool vis[100005];
vector<int> adj[100005];

double dfs(int s)
{
    vis[s] = 1;

    int cnt = 0;
    double ret = 0;

    for(auto u : adj[s])
    {
        if(!vis[u])
        {
            cnt++;
            ret += dfs(u) + 1;
        }
    }

    if(!cnt)
        return 0;

    return ret / cnt;
}

int main()
{
    int n, i, u, v;

    cin >> n;

    for(i = 1; i < n; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << fixed << setprecision(7) << dfs(1);
}
