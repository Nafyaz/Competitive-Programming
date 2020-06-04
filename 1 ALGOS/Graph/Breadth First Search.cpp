#include<bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> adj[], bool vis[])
{
    int i, j, node;
    queue <int> q;
    q.push(s);
    vis[s] = 1;

    while(!q.empty())
    {
        i = q.front();
        printf("%d ", i);
        q.pop();
        for(j = 0; j < adj[i].size(); j++)
        {
            node = adj[i][j];
            if(!vis[node])
            {
                q.push(node);
                vis[node] = 1;
            }
        }
    }
    printf("\n");
}

int main()
{
    int t, n, m, i, u, v;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        vector <int> adj[n+1];
        bool vis[n+1] = {0};

        for(i = 1; i <= m; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfs(0, adj, vis);

    }
}
