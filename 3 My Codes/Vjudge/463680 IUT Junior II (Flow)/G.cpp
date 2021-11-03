#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second

int cap[65][65], par[65];
vector<int> adj[65];

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
        int cur = t;

        while(cur != s)
        {
            int prev = par[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main()
{
    int T, caseno = 0, i, j, n, m, s, t;
    map<string, int> mp;
    mp["XXL"] = 55;
    mp["XL"] = 56;
    mp["L"] = 57;
    mp["M"] = 58;
    mp["S"] = 59;
    mp["XS"] = 60;

    s = 0;
    t = 61;

    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        for(i = 0; i < 65; i++)
        {
            adj[i].clear();
            for(j = 0; j < 65; j++)
            {
                cap[i][j] = 0;
                cap[j][i] = 0;
            }
        }

        for(i = 55; i <= 60; i++)
        {
            cap[i][t] = n;
            adj[i].pb(t);
            adj[t].pb(i);
        }

        for(i = 1; i <= m; i++)
        {
            cap[s][i] = 1;
            adj[s].pb(i);
            adj[i].pb(s);
        }

        for(i = 1; i <= m; i++)
        {
            string sz1, sz2;
            cin >> sz1 >> sz2;
            int ms1 = mp[sz1], ms2 = mp[sz2];
            cap[i][ms1] = 1;
            adj[i].pb(ms1);
            adj[ms1].pb(i);

            cap[i][ms2] = 1;
            adj[i].pb(ms2);
            adj[ms2].pb(i);
        }

        cout << "Case " << ++caseno << ": " << (maxflow(s, t) == m? "YES" : "NO") << endl;
    }
}

