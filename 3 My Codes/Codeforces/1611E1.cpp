#include<bits/stdc++.h>
using namespace std;

int x[200005], dis[200005];
vector<int> adj[200005];

void bfs(int s)
{
    queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto u : adj[node])
        {
            if(dis[u] > dis[node] + 1)
            {
                dis[u] = dis[node] + 1;
                q.push(u);
            }
        }
    }
}

bool dfs(int s, int p, int d)
{
    if(d >= dis[s])
        return 0;

    if(s != 1 && adj[s].size() == 1)
        return 1;

    bool ret = 0;
    for(auto u : adj[s])
    {
        if(u != p)
            ret = max(ret, dfs(u, s, d+1));
    }

    return ret;
}

int main()
{
    int T, n, k, i, u, v;

    cin >> T;

    while(T--)
    {
        cin >> n >> k;

        for(i = 1; i <= n; i++)
        {
            adj[i].clear();
            dis[i] = INT_MAX;
        }

        for(i = 1; i <= k; i++)
        {
            cin >> x[i];
            dis[x[i]] = 0;
        }

        for(i = 1; i < n; i++)
        {
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(i = 1; i <= k; i++)
            bfs(x[i]);

        if(dfs(1, -1, 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
