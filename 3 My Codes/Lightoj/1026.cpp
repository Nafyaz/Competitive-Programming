#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n;
bool vis[10009];
int tin[10009], low[10009], timer;
vector<int> adj[10009];
set<pair<int, int>> bridge;

void dfs(int v, int p = -1)
{
    vis[v] = 1;
    timer++;
    tin[v] = low[v] = timer;

    for(auto to : adj[v])
    {
        if(to == p)
            continue;
        if(!vis[to])
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);

            if(low[to] > tin[v])
                bridge.insert({min(v, to), max(v, to)});
        }
        else
            low[v] = min(low[v], tin[to]);
    }
}

void findBR()
{
    timer = 0;
    bridge.clear();
    int i;
    for(i = 0; i < n; i++)
    {
        vis[i] = 0;
        tin[i] = -1;
        low[i] = -1;
    }

    for(i = 0; i < n; i++)
    {
        if(!vis[i])
            dfs(i);
    }
}

int main()
{
    char c;
    int a, b, sz, i, t, caseno = 0;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            adj[i].clear();
        for(i = 0; i < n; i++)
        {
            cin >> a;
            cin >> c;
            cin >> sz;
            cin >> c;
            while(sz--)
            {
                cin >> b;
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
        }

        findBR();

        cout << "Case " << ++caseno << ":\n" << bridge.size() << " critical links\n";
        for(auto u : bridge)
            cout << u.ff << " - " << u.ss << endl;
    }
}
/*
3

8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)

0

2
0 (1) 1
1 (1) 0
*/

