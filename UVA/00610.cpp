#include<bits/stdc++.h>
using namespace std;

int n, m;
bool vis[1009];
int tin[1009], low[1009], timer;
vector<int> adj[1009];
map<pair<int, int>, bool> edge;

void dfs(int v, int p = -1)
{
    vis[v] = 1;
    timer++;
    tin[v] = low[v] = timer;

    for(auto to : adj[v])
    {
        if(to == p)
            continue;

        if(edge.find({v, to}) != edge.end())
            cout << v << " " << to << endl;

        edge[{to, v}] = 1;
        edge[{v, to}] = 1;

        if(!vis[to])
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] > tin[v])
                cout << to << "*" << v << endl;
        }
        else
            low[v] = min(low[v], tin[to]);

    }
}

void findBR()
{
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
    int i, a, b, caseno = 0;
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

        cout << ++caseno << endl << endl;
        findBR();
        cout << "#\n";
    }
}
/*
7  10
1  2
1  3
2  4
3  4
4  5
4  6
5  7
6  7
2  5
3  6

7  9
1  2
1  3
1  4
2  4
3  4
4  5
5  6
5  7
7  6
0  0
*/
