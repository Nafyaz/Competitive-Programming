#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second

int cap[109][109], par[109];
vector<int> adj[109];

int bfs(int s, int t)
{
    memset(par, -1, sizeof par);
    par[s] = -2;

    queue<pair<int, int> > q;
    q.push({s, INT_MAX});

    while(!q.empty())
    {
        int cur = q.front().ff;
        int flow = q.front().ss;
        q.pop();
        for(auto next : adj[cur])
        {
            if(par[next] == -1 && cap[cur][next])
            {
                par[next] = cur;
                int new_flow = min(flow, abs(cap[cur][next]));
                if(next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t)
{
    int flow = 0, new_flow;

    while(new_flow = bfs(s, t))
    {
        flow += new_flow;
        int cur = t;
        while(cur != s)
        {
            int prev = par[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = par[cur];
        }
    }

    return flow;
}

int main()
{
    int T, caseno = 0, m, w, i;
    cin >> T;
    while(T--)
    {
        cin >> m >> w;
        for(i = 0; i < 109; i++)
            adj[i].clear();
        memset(cap, 0, sizeof cap);
        memset(par, 0, sizeof par);

        for(i = 2; i < m; i++)
        {
            int c;
            cin >> c;
            adj[i].pb(i+m);
            adj[i+m].pb(i);
            cap[i][i+m] = c;
        }
        for(i = 0; i < w; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if(a > b)
                swap(a, b);
            if(a == 1 && b == m)
            {
                cap[a][b] = c;
                cap[b][a] = c;
                adj[a].pb(b);
                adj[b].pb(a);
            }
            else if(a == 1)
            {
                cap[a][b] = c;
                cap[b+m][a] = c;
                adj[a].pb(b);
                adj[b+m].pb(a);
            }
            else if(b == m)
            {
                cap[a+m][b] = c;
                cap[b][a] = c;
                adj[a+m].pb(b);
                adj[b].pb(a);
            }
            else
            {
                cap[a+m][b] = c;
                cap[b+m][a] = c;
                adj[a+m].pb(b);
                adj[b+m].pb(a);
            }
        }

        cout << "Case " << ++caseno << ": " << maxflow(1, m) << endl;
    }
}
