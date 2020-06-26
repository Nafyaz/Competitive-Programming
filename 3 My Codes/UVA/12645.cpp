#include<bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector<int> g[1009];
int vis[1009];
vector<int> order;

void dfs(int v, bool f)
{
    vis[v] = 1;
    for(auto u : g[v])
    {
        if(!vis[u])
            dfs(u, f);
    }
    if(f)
        order.push_back(v);
}

int main()
{
    int i;
    while(cin >> n >> m)
    {
        for(i = 0; i <= n; i++)
            g[i].clear();


        for(i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
        }

        for(i = 0; i <= n; i++)
            vis[i] = 0;
        order.clear();
        for(i = 0; i <= n; i++)
        {
            if(!vis[i])
                dfs(i, 1);
        }

        int ans = 0;
        for(i = 0; i <= n; i++)
            vis[i] = 0;
        for(i = n; i >= 0; i--)
        {
            int v = order[i];
            if(!vis[v])
            {
                dfs(v, 0);
                if(v != 0)
                    ans++;
            }
        }

        cout << ans << endl;
    }
}
/*
4 5
0 1
1 2
2 1
0 4
3 4
4 2
3 1
2 1
*/
