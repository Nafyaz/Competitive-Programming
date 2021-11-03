#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second

int cap[209][209], par[209];
vector<int> adj[209];

int bfs(int s, int t)
{
    memset(par, -1, sizeof par);
    par[s] = -2;

    queue<pair<int, int>> q;
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
                int new_flow = min(flow, cap[cur][next]);
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
        for(int cur = t; cur != s; cur = par[cur])
        {
            int prev = par[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
        }
    }
    return flow;
}

int main()
{
    int T, caseno = 0, n, m, i, j, a[209];
    cin >> T;
    while(T--)
    {
        for(i = 0; i < 209; i++)
            adj[i].clear();
        memset(cap, 0, sizeof cap);

        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> a[i];
            cap[0][i] = 1;
//            cap[i][0] = 1;
            adj[0].pb(i);
            adj[i].pb(0);
        }
        cin >> m;
        for(i = n+1; i <= n+m; i++)
        {
            cin >> a[i];
            for(j = 1; j <= n; j++)
            {
                if(a[i]%a[j] == 0)
                {
//                    cap[i][j] = 1;
                    cap[j][i] = 1;
                    adj[i].pb(j);
                    adj[j].pb(i);
                }
            }
            cap[i][n+m+1] = 1;
//            cap[n+m+1][i] = 1;
            adj[i].pb(n+m+1);
            adj[n+m+1].pb(i);
        }

        cout << "Case " << ++caseno << ": " << maxflow(0, n+m+1) << endl;
    }
}
