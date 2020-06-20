#include<bits/stdc++.h>
using namespace std;

int n, m, vis[100009], dis[100009];
vector<int> adj[100009];

int dfs(int s)
{
    if(vis[s])
        return dis[s];
    vis[s] = 1;
    int ret = 0;
    for(auto u : adj[s])
        ret = max(ret, dfs(u) + 1);

    return dis[s] = ret;
}

int main()
{
    int i;
    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    int ans = 0;
    for(i = 1; i <= n; i++)
    {
        if(!vis[i])
            ans = max(ans, dfs(i));
    }

    cout << ans;
}
