#include<bits/stdc++.h>
using namespace std;

int dis[2009], n;
bool mat[2009][2009], vis[2009];
vector<int> adj[2009];

int bfs(int s)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
        vis[i] = 0;
    }

    dis[s] = 0;
    queue<int> q;
    q.push(s);
    vis[s] = 1;

    while(!q.empty())
    {
        int u = q.front();
        if(mat[u][s])
            return dis[u];
        q.pop();
        for(auto v : adj[u])
        {
            if(!vis[v])
            {
                dis[v] = dis[u] + 1;
                q.push(v);
                vis[v] = 1;
                if(mat[v][s])
                    return dis[v];
            }
        }
    }

    return INT_MAX;
}

int main()
{
    int i, j, k, ans;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &mat[i][j]);
            if(mat[i][j])
                adj[i].push_back(j);
        }
    }

    for(i = 1; i <= n; i++)
    {
        ans = bfs(i);

        if(ans == INT_MAX)
            printf("NO WAY\n");
        else
            printf("%d\n", ans + 1);
    }
}

