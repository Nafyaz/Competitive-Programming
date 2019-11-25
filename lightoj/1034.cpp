#include<bits/stdc++.h>
using namespace std;

vector <int> adj[10010];
int n, vis[10010], in_degree[10010];
queue <int> q;

void bfs()
{
    int node;
    while(!q.empty())
    {
        node = q.front();
        q.pop();
        vis[node] = 1;

        for(auto i : adj[node])
        {
            if(vis[i] == 0)
                q.push(i);
        }
    }
}

void dfs(int s)
{
    vis[s] = 1;
    for(auto node : adj[s])
    {
        if(vis[node] == 0)
            dfs(node);
    }
}


int main()
{
    int t, m, i, u, v, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        memset(vis, 0, sizeof(vis));
        memset(in_degree, 0, sizeof(in_degree));

        scanf("%d %d", &n, &m);
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
        }

        for(i = 1; i <= n; i++)
        {
            for(auto j : adj[i])
                in_degree[j]++;
        }

        int ans = 0;

        for(i = 1; i <= n; i++)
        {
            if(in_degree[i] == 0)
            {
                q.push(i);
                ans++;
                vis[i] = 1;
            }
        }

        bfs();

        for(i = 1; i <= n; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i);
                ans++;
            }
        }

        printf("Case %d: %d\n", ++caseno, ans);

        for(i = 1; i <= n; i++)
            adj[i].clear();
    }
    return 0;
}
