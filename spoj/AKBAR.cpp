#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int vis[1000009], c;
vector<int> adj[1000009];

int bfs(int node, int s)
{
    pair<int, int> p;
    queue<pair<int, int>> q;
    if(vis[node] != 0 && vis[node] != c)
        return 0;
    vis[node] = c;
    q.push({0, node});

    while(!q.empty())
    {
        p = q.front();
        q.pop();

        if(p.ff >= s)
            break;
        for(auto u : adj[p.ss])
        {
            if(vis[u] != 0 && vis[u] != c)
                return 0;
            if(vis[u] == c)
                continue;
            vis[u] = c;
            q.push({p.ff+1, u});
        }

    }
    return 1;
}

int main()
{
    int t, n, r, m, i, j, u, v, k, s, f;
    cin >> t;
    while(t--)
    {
        cin >> n >> r >> m;
        for(i = 0; i <= n; i++)
        {
            adj[i].clear();
            vis[i] = 0;
        }
        for(i = 0; i < r; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        c = 0;
        f = 1;
        for(i = 0; i < m; i++)
        {
            cin >> k >> s;
            c++;
            f = min(f, bfs(k, s));
        }

        if(f == 0)
        {
            cout << "No" << endl;
            continue;
        }

        for(i = 1; i <= n; i++)
        {
            if(!vis[i])
            {
                f = 0;
                break;
            }
        }

        cout << (f? "Yes" : "No") << endl;
    }
}
