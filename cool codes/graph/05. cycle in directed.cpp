#include <bits/stdc++.h>
using namespace std;

bool vis[10010];
vector <int> adj[10010];

bool dfs(int u)
{
    if(vis[u])
        return 1;

    vis[u] = 1;

    int i, node;
    bool ans = 0;
    for(i = 0; i < adj[u].size(); i++)
    {
        node = adj[u][i];
        ans = max(ans, dfs(node));
    }
    return ans;
}

bool isCyclic(int v)
{
    int i, found = 0;
    for(i = 0; i < v; i++)
    {
        if(found)
            return 1;

        if(!vis[i])
            found = dfs(i);
    }
    return found;
}

int main()
{
    int v, e;
    cin >> v >> e;

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << isCyclic(v) << endl;

	return 0;
}
