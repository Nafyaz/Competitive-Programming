#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> g[5009], gr[5009];
int vis[5009], compo[5009], cnt;
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

    while(1)
    {
        cin >> n;
        if(!n)
            return 0;

        for(i = 1; i <= n; i++)
        {
            g[i].clear();
            gr[i].clear();
            vis[i] = 0;
        }

        cin >> m;
        for(i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            gr[b].push_back(a);
        }

        order.clear();
        for(i = 1; i <= n; i++)
        {
            if(!vis[i])
                dfs1(i);
        }

        for(i = 1; i <= n; i++)
            vis[i] = 0;

        cnt = 0;
        for(i = 1; i <= n; i++)
        {
            int v = order[n-i];
            if(!vis[v])
            {
                cnt++;
                dfs2(v);
            }
        }

        set<int> s;
        for(i = 1; i <= cnt; i++)
            s.insert(i);
        for(i = 1; i <= n; i++)
        {
            if(s.find(compo[i]) == s.end())
                continue;
            for(auto u : g[i])
            {
                if(compo[i] != compo[u])
                {
                    s.erase(compo[i]);
                    break;
                }
            }
        }

        for(i = 1; i <= n; i++)
        {
            if(s.find(compo[i]) != s.end())
                cout << i << " ";
        }
        cout << endl;
    }
}
