#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int N, M;
vector<pair<int, int>> adj[20004];
int cap[20004][20004];
int par[20004];

int bfs(int s, int t, int mx)
{
    int cur, flow, next, new_flow;

    memset(par, -1, sizeof par);
    par[s] = -2;

    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

    while(!q.empty())
    {
        cur = q.front().ff;
        flow = q.front().ss;

        q.pop();

        for(auto p : adj[cur])
        {
            if(p.ss > mx)
                continue;

            next = p.ff;

            if(par[next] == -1 && cap[cur][next])
            {
                new_flow = min(flow, cap[cur][next]);
                par[next] = cur;

                if(next == t)
                    return new_flow;

                q.push({next, new_flow});
            }
        }
    }

    return 0;
}


int maxFlow(int s, int t, int mx)
{
    int flow = 0, new_flow, i;

    for(i = 1; i <= N; i++)
    {
        cap[s][i] = 1;

        for(auto u : adj[i])
        {
            if(u.ff != s)
                cap[i][u.ff] = 1;
        }

        cap[i+N][t] = 1;
    }

    while(new_flow = bfs(s, t, mx))
    {
        flow += new_flow;

        int prev, cur;

        for(cur = t; cur != s; cur = prev)
        {
            prev = par[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
        }
    }

    return flow;
}

int main()
{
    int u, v, d, i;

    cin >> N >> M;

    int source = 0, sink = 2*N+1;

    for(i = 1; i <= N; i++)
    {
        adj[source].push_back({i, 0});
        adj[i].push_back({source, 0});

        adj[i+N].push_back({sink, 0});
        adj[sink].push_back({i+N, 0});
    }

    for(i = 0; i < M; i++)
    {
        cin >> u >> v >> d;

        adj[u].push_back({N+v, d});
        adj[N+v].push_back({u, d});
    }

    int low = 1, high = 1000000009, mid, ans = -1;

    while(low <= high)
    {
        mid = (low + high)/2;

        if(maxFlow(source, sink, mid) == N)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout << ans;
}
