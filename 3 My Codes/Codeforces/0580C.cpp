#include<bits/stdc++.h>
using namespace std;

int ans, n, mcat, cats[100010];
vector<int> adj[100010];
vector<int> :: iterator it;

void clear_back(int node, int parent)
{
    it = find(adj[node].begin(), adj[node].end(), parent);
    if(it != adj[node].end())
        adj[node].erase(it);
    for(auto u : adj[node])
        clear_back(u, node);
}


void dfs(int node, int c)
{
    if(cats[node])
        c++;
    else
        c = 0;

    if(c > mcat)
        return;

    if(adj[node].size() == 0)
    {
        if(c <= mcat)
            ans++;
        return;
    }

    for(auto u : adj[node])
        dfs(u, c);
}



int main()
{
    int i, u, v;
    scanf("%d %d", &n, &mcat);

    for(i = 1; i <= n; i++)
        scanf("%d", &cats[i]);

    for(i = 1; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    clear_back(1, 0);
    dfs(1, 0);

    printf("%d", ans);
}
