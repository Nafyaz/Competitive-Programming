#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int vis[5003];
vector<int> adj[5003];
stack<int> stk;

void dfs1(int s)
{
    vis[s] = 1;

    for(auto u : adj[s])
    {
        if(!vis[u])
            dfs1(u);
    }
}

void dfs2(int s)
{
    vis[s] = 1;

    for(auto u : adj[s])
    {
        if(!vis[u])
            dfs2(u);
    }

    stk.push(s);
}

int main()
{
    int n, m, s, i, u, v, ans;

    cin >> n >> m >> s;

    for(i = 0; i < m; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);
    }

    dfs1(s);

    for(i = 1; i <= n; i++)
    {
        if(!vis[i])
            dfs2(i);
    }

    ans = 0;
    memset(vis, 0, sizeof vis);
    while(!stk.empty())
    {
        if(!vis[stk.top()])
        {
            dfs1(stk.top());
            ans++;
        }
        stk.pop();
    }

    cout << ans;
}
