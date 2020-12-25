#include<bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector<int> g[1009], gr[1009];
int vis[1009], compo[1009], in[1009];
vector<int> order;

void dfs1(int v)
{
    vis[v] = 1;
    for(auto u : g[v])
    {
        if(!vis[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v)
{
    vis[v] = 1;
    compo[v] = cnt;
    for(auto u : gr[v])
    {
        if(!vis[u])
            dfs2(u);
    }
}

int main()
{
    int i, j;
    while(cin >> n >> m)
    {
        for(i = 0; i <= n; i++)
        {
            g[i].clear();
            gr[i].clear();
        }
        for(i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            gr[b].push_back(a);
        }

        for(i = 0; i <= n; i++)
            vis[i] = 0;
        order.clear();
        for(i = 0; i <= n; i++)
        {
            if(!vis[i])
                dfs1(i);
        }

        cnt = 0;
        for(i = 0; i <= n; i++)
        {
            vis[i] = 0;
            in[i] = 0;
        }
        for(i = n; i >= 0; i--)
        {
            int v = order[i];
            if(!vis[v])
            {
                cnt++;
                dfs2(v);
            }
        }

        for(i = 0; i <= n; i++)
        {
            for(auto u : g[i])
            {
                int ci = compo[i], cu = compo[u];
                if(ci != cu)
                    in[cu]++;
            }
        }

        int ans = 0;
        for(i = 1; i <= cnt; i++)
        {
            if(in[i] == 0 && i != compo[0])
                ans++;
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

