#include<bits/stdc++.h>
using namespace std;

const int N = 10009;
vector <int> g[N], gr[N];
bool vis[N];
vector<int> order, component;

void dfs1(int v)
{
    vis[v] = 1;
    for (auto u : g[v])
    {
        if (!vis[u])
            dfs1(u);
    }
    order.push_back (v);
}

void dfs2(int v)
{
    vis[v] = 1;
    component.push_back(v);
    for (auto u : gr[v])
    {
        if(!vis[u])
            dfs2(u);
    }
}

int main()
{
    int n, m, i, cnt = 0;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back (b);
        gr[b].push_back (a);
    }

    memset(vis, 0, sizeof vis);
    for (i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs1(i);
    }

    memset(vis, 0, sizeof vis);
    for (i = 1; i <= n; i++)
    {
        int v = order[n-i];
        if (!vis[v])
        {
            dfs2 (v);
            cout << "Component No. " << ++cnt << ": ";
            for(auto u : component)
                cout << u << " ";
            cout << endl;
            component.clear();
        }
    }
}