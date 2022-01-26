#include<bits/stdc++.h>
using namespace std;

int a[100005];
vector<int> adj[100005];
bool vis[100005];
set<int> s;

int main()
{
    int n, m, i, u, v, node;

    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(i = 0; i < n; i++)
        cin >> a[i];

    int ans = -1;

    if(a[0] != n)
        ans = 0;

    s.insert(a[0]);
    vis[a[0]] = 1;
    for(i = 0; i < n; i++)
    {
        s.erase(a[i]);
        for(auto u : adj[a[i]])
        {
            if(!vis[u])
            {
                vis[u] = 1;
                s.insert(u);
            }
        }

        if(s.lower_bound(a[i+1]) != s.end())
            ans = i+1;
    }

    if(ans == -1)
    {
        cout << -1;
        return 0;
    }

    s.clear();
    memset(vis, 0, sizeof vis);

    for(i = 0; i < ans; i++)
    {
        cout << a[i] << " ";
        s.insert(a[i]);
        vis[a[i]] = 1;

        for(auto u : adj[a[i]])
            s.insert(u);
    }

    while(!s.empty())
    {
        node = *s.begin();
        s.erase(node);

        if(vis[node])
            continue;

        cout << node << " ";
        vis[node] = 1;

        for(auto u : adj[node])
            s.insert(u);
    }
}

