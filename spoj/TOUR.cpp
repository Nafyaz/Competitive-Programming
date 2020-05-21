#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> g[1009], gr[1009];
int vis[1009], composz;
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
    composz++;
    for(auto u : gr[v])
    {
        if(!vis[u])
            dfs2(u);
    }
}

int main()
{
    int t, i, j, m, a;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            g[i].clear();
            gr[i].clear();
        }
        for(i = 1; i <= n; i++)
        {
            cin >> m;
            for(j = 0; j < m; j++)
            {
                cin >> a;
                g[a].push_back(i);
                gr[i].push_back(a);
            }
        }

        memset(vis, 0, sizeof vis);
        order.clear();
        for(i = 1; i <= n; i++)
        {
            if(!vis[i])
                dfs1(i);
        }
        int v = order[n-1];

        memset(vis, 0, sizeof vis);
        order.clear();
        dfs1(v);
        if(order.size() < n)
        {
            cout << 0 << endl;
            continue;
        }

        memset(vis, 0, sizeof vis);
        composz = 0;
        dfs2(v);

        cout << composz << endl;
    }
}
