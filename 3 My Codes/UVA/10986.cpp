#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back

vector<pair<int, int>> adj[20009];
int dis[20009];

void djikstra(int s)
{
    set<pair<int, int>> q;

    q.insert({0, s});
    dis[s] = 0;

    while(!q.empty())
    {
        pair<int, int> p = *q.begin();
        q.erase(q.begin());

        int node = p.ss;
        if(p.ff > dis[node])
            continue;

        for (auto u : adj[node])
        {
            int len = u.ff;
            int to = u.ss;
            if (dis[to] == -1 || dis[node] + len < dis[to])
            {
                dis[to] = dis[node] + len;
                q.insert({dis[to], to});
            }
        }
    }
}

int main()
{
    int T, caseno = 0;
    cin >> T;

    while(T--)
    {
        int i, n, m, u, v, w, s, t;

        cin >> n >> m >> s >> t;

        for(i = 0; i < n; i++)
        {
            adj[i].clear();
            dis[i] = -1;
        }

        for(i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            adj[u].pb({w, v});
            adj[v].pb({w, u});
        }

        djikstra(s);

        if(dis[t] == -1)
            cout << "Case #" << ++caseno << ": unreachable\n";
        else
            cout << "Case #" << ++caseno << ": " << dis[t] << "\n";
    }
}
