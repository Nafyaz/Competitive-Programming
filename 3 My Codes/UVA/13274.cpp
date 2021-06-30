#include<bits/stdc++.h>
using namespace std;

int k;
vector<int> adj[1009];

int dfs(int node, int parent)
{
    int ret = 1;
    priority_queue<int> pq;

    for(auto u : adj[node])
    {
        if(u != parent)
            pq.push(dfs(u, node));
    }

    if(pq.size() >= k)
    {
        for(int i = 0; i < k; i++)
        {
            ret += pq.top();
            pq.pop();
        }
    }

    return ret;
}

int main()
{
    int t, caseno = 0, n, i, u, v;

    cin >> t;
    while(t--)
    {
        cin >> n >> k;

        for(i = 1; i <= n; i++)
            adj[i].clear();

        for(i = 1; i < n; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << "Case " << ++caseno << ": " << dfs(1, 0) << "\n";
    }
}

