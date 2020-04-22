#include<bits/stdc++.h>
using namespace std;

int n, m;
bool vis[10009];
int tin[10009], low[10009], timer;
vector<int> adj[10009];
set<int> AP;

void dfs(int v, int p = -1)
{
    vis[v] = 1;
    timer++;
    tin[v] = low[v] = timer;

    int child = 0;
    for(auto to : adj[v])
    {
        if(to == p)
            continue;
        if(!vis[to])
        {
            child++;
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] >= tin[v] && p != -1)
                AP.insert(v);
        }
        else
            low[v] = min(low[v], tin[to]);
    }

    if(p == -1 && child > 1)
        AP.insert(v);
}

void findAP()
{
    AP.clear();
    timer = 0;
    int i;
    for(i = 1; i <= n; i++)
    {
        vis[i] = 0;
        tin[i] = -1;
        low[i] = -1;
    }

    for(i = 1; i <= n; i++)
    {
        if(!vis[i])
            dfs(i);
    }
}

int main()
{
    int i, a, b;
    while(1)
    {
        cin >> n >> m;
        if(!n && !m)
            break;

        for(i = 1; i <= n; i++)
            adj[i].clear();

        for(i = 1; i <= m; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        findAP();

//        cout << *AP.begin();
        cout << AP.size() << endl;
    }
}
