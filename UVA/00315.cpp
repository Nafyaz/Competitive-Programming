#include<bits/stdc++.h>
using namespace std;

int n;
bool vis[109];
int tin[109], low[109], timer;
vector<int> adj[109];
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
    timer = 0;
    AP.clear();
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
    string s;
    int u, v, i;
    while(1)
    {
        cin >> n;
        if(!n)
            break;

        for(i = 1; i <= n; i++)
            adj[i].clear();

        while(1)
        {
            cin >> u;
            if(!u)
                break;
            getline(cin, s);
            stringstream ss(s);
            while(ss >> s)
            {
                v = stoi(s);
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        findAP();

        cout << AP.size() << endl;
    }
}
/*
5
5  1  2  3  4
0
6
2  1  3
5  4  6  2
0
0
*/
