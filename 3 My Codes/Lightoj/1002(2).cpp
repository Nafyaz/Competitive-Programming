#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

vector<pair<int, int>> adj[509];
int dis[509];

void djikstra(int s)
{
    set<pair<int, int> > q;

    q.insert({0, s});
    dis[s] = 0;

    while(!q.empty())
    {
        pair<int, int> p = *q.begin();
        q.erase(q.begin());

        int node = p.ss;
        if(p.ff > dis[node])
            continue;

        for(auto u : adj[node])
        {
            int len = u.ff;
            int to = u.ss;

            if(dis[to] > max(dis[node], len))
            {
                dis[to] = max(dis[node], len);
                q.insert({dis[to], to});
            }
        }
    }
}

int main()
{
    int T, caseno = 0, i, n, m, u, v, w, t;

    cin >> T;

    while(T--)
    {
        cin >> n >> m;

        for(i = 0; i < n; i++)
        {
            dis[i] = INT_MAX;
            adj[i].clear();
        }

        for(i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            adj[u].pb({w, v});
            adj[v].pb({w, u});
        }
        cin >> t;

        djikstra(t);

        cout << "Case " << ++caseno << ":\n";
        for(i = 0; i < n; i++)
        {
            dis[i] == INT_MAX? cout << "Impossible\n" : cout << dis[i] << "\n";
        }
    }
}
