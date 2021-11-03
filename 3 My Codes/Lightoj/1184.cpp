#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int cap[102][102], par[102];
vector<int> adj[102];

struct person
{
    int id, height, age;
    bool divorced;
};

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
    int t, caseno = 0, m, n, i, j, id = 0, source, sink;
    person man[51], woman[51];
    cin >> t;

    while(t--)
    {
        cin >> m >> n;

        id = 0;
        memset(cap, 0, sizeof cap);
        for(i = 0; i < 102; i++)
            adj[i].clear();

        source = id++;
        sink = id++;

        for(i = 0; i < m; i++)
        {
            man[i].id = id++;
            cin >> man[i].height >> man[i].age >> man[i].divorced;

            adj[source].push_back(man[i].id);
            adj[man[i].id].push_back(source);
            cap[source][man[i].id] = 1;
        }
        for(i = 0; i < n; i++)
        {
            woman[i].id = id++;
            cin >> woman[i].height >> woman[i].age >> woman[i].divorced;

            adj[woman[i].id].push_back(sink);
            adj[sink].push_back(woman[i].id);
            cap[woman[i].id][sink] = 1;
        }


        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(abs(man[i].height - woman[j].height) <= 12 && abs(man[i].age - woman[j].age) <= 5 && man[i].divorced == woman[j].divorced)
                {
                    adj[man[i].id].push_back(woman[j].id);
                    adj[woman[j].id].push_back(man[i].id);
                    cap[man[i].id][woman[j].id] = 1;
                }
            }
        }

        cout << "Case " << ++caseno << ": " << maxflow(source, sink) << "\n";
    }
}
