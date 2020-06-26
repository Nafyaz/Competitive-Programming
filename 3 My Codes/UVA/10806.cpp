#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back

int n, cap[109][109], par[109];
int ans, w[109][109], dis[109];
vector<pair<int, int>> adj[109];

void init()
{
    for(int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
        par[i] = -1;
    }
}

int dijkstra(int s, int t)
{
    init();

    dis[s] = 0;
    par[s] = -2;
    set<pair<int, int>> q;
    q.insert({dis[s], s});

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
            if(p.ff + len < dis[to] && cap[node][to])
            {
                dis[to] = p.ff + len;
                q.insert({dis[to], to});
                par[to] = node;
            }
        }
    }

    return dis[t] != INT_MAX;
}

int maxflow(int s, int t)
{
    int flow = 0, new_flow;

    while(new_flow = dijkstra(s, t))
    {
        flow += new_flow;
        for(int cur = t; cur != s; cur = par[cur])
        {
            int prev = par[cur];

            if(cap[prev][cur] == 2)
                ans -= w[prev][cur];
            else
                ans += w[prev][cur];

            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
        }

        if(flow == 2)
            break;
    }

    return flow;
}

int main()
{
    int m, i;
    while(1)
    {
        cin >> n;
        if(!n)
            return 0;
        for(i = 1; i <= n; i++)
            adj[i].clear();
        memset(cap, 0, sizeof cap);
        memset(w, 0, sizeof w);
        ans = 0;

        cin >> m;
        for(i = 1; i <= m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].pb({c, b});
            adj[b].pb({c, a});
            cap[a][b] = 1;
            cap[b][a] = 1;
            w[a][b] = c;
            w[b][a] = c;
        }

//        cout << dijkstra(1, n) << endl;

        if(maxflow(1, n) == 2)
            cout << ans << endl;
        else
            cout << "Back to jail" << endl;
    }
}
