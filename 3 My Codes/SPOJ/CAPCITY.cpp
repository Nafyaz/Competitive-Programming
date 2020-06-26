#include<bits/stdc++.h>
using namespace std;

int n, m, compo[100009], out[100009], cnt;
vector<int> g[100009], gr[100009];
set <int> C[100009];
bool vis[100009];
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
    cin >> n >> m;
    int i;
    for(i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }


    for(i = 1; i <= n; i++)
    {
        if(!vis[i])
            dfs1(i);
    }

    memset(vis, 0, sizeof vis);
    for(i = 1; i <= n; i++)
    {
        int v = order[n-i];
        if(!vis[v])
        {
            cnt++;
            dfs2(v);
        }
    }

    for(i = 1; i <= n; i++)
    {
        for(auto u : g[i])
        {
            int ci = compo[i], cu = compo[u];
            if(ci != cu && C[ci].find(cu) == C[ci].end())
            {
                C[ci].insert(cu);
                out[ci]++;
            }
        }
    }

    int v = -1;
    for(i = 1; i <= cnt; i++)
    {
        if(out[i] == 0 && v != -1)
        {
            cout << 0;
            return 0;
        }
        else if(out[i] == 0)
            v = i;
    }

    vector<int> ans;
    for(i = 1; i <= n; i++)
    {
        if(compo[i] == v)
            ans.push_back(i);
    }

    cout << ans.size() << endl;
    for(auto u : ans)
        cout << u << " ";
}
