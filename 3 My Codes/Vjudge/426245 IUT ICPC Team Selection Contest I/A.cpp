#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1009];
int child[1009], parent[1009];
bool ingraph[1009];

void dfs(int v)
{
    for(auto u : adj[v])
    {
        if(u != parent[v])
        {
            child[v]++;
            parent[u] = v;
            dfs(u);
        }
    }
}

vector<int> path;

void topsort(int n)
{
    queue<int> Q;
    int i;
    for(i = 1; i <= n; i++)
    {
        if(child[i] == 0)
            Q.push(i);
    }
    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        path.push_back(u);
        for(auto u : adj[node])
        {
            child[u]--;
            if(child[u] == 0)
                Q.push(u);
        }
    }
}

int main()
{
    int t, caseno = 0, n, k, i;

    cin >> t;
    while(t--)
    {
        cin >> n >> k;

        for(i = 0; i < n; i++)
        {
            adj[i].clear();
            child[i] = 0;
            parent[i] = 0;
            ingraph[i] = 0;
        }

        for(i = 1; i < n; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);

            ingraph[u] = ingraph[v] = 1;
        }

        dfs(1);

        for(i = 0; i < n; i++)
        {
            int x = path[i];
            if(child[x] < k && child[x] != 0)
            {
                child[parent[x]] --;
                ingraph[x] = 0;
            }
        }

        for(i = 0; i < )
    }
}
