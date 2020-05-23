#include<bits/stdc++.h>
using namespace std;

vector <int> adj[10010], path;
int n, vis[10010];

void dfs(int s, bool f)
{
    vis[s] = 1;
    for(auto node : adj[s])
    {
        if(vis[node] == 0)
            dfs(node, f);
    }
    if(f)
        path.push_back(s);
}


int main()
{
    int t, m, i, u, v, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);

        for(i = 1; i <= n; i++)
            adj[i].clear();
        memset(vis, 0, sizeof(vis));

        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
        }

        path.clear();
        for(i = 1; i <= n; i++)
        {
            if(!vis[i])
                dfs(i, 1);
        }

        int ans = 0;
        memset(vis, 0, sizeof vis);
        for(i = n-1; i >= 0; i--)
        {
            int v = path[i];
            if(!vis[v])
            {
                dfs(v, 0);
                ans++;
            }
        }

        printf("Case %d: %d\n", ++caseno, ans);
    }
}
