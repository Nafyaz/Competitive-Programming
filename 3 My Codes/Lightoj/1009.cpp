#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, e, u, v, ans, node, j, caseno = 0;
    scanf("%d", &t);
    while(t--)
    {
        int vis[20010] = {0};
        vector<int> dis;
        vector<int> adj[20010];
        scanf("%d", &e);
        for(i = 0; i < e; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);

            if(!vis[u])
                dis.push_back(u);
            if(!vis[v])
                dis.push_back(v);

            vis[u] = vis[v] = 1;
        }

        memset(vis, 0, sizeof(vis));

        queue<int> q;
        ans = 0;
        for(auto i : dis)
        {
            int vamp = 0, lyk = 0;

            if(vis[i] != 0)
                continue;

            q.push(i);
            vamp++;
            vis[i] = 1;

            while(!q.empty())
            {
                u = q.front();
                q.pop();

//                printf("%d ", u);

                for(auto j : adj[u])
                {

                    node = j;
                    //printf("%d %d %d", u, j, adj[1][0]);
                    if(vis[node] == 0)
                    {
                        q.push(node);
                        vis[node] = -vis[u];
                        vis[node] == 1? vamp++ : lyk++;
                    }
                }

            }
            ans += max(vamp, lyk);
        }
        printf("Case %d: %d\n", ++caseno, ans);
    }
}
