#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n, dis[109];
vector<pair<int, int>> adj[109];

void init()
{
    for(int i = 1; i <= n; i++)
        dis[i] = INT_MAX;
}

void dijkstra(int s)
{
    init();

    set<pair<int, int>> q;
    dis[s] = 0;
    q.insert({0, s});

    while(!q.empty())
    {
        int node = q.begin() -> ss;
        q.erase(q.begin());

        for(auto u : adj[node])
        {
            int to = u.ss;
            int len = u.ff;
            if(dis[to] > dis[node] + len)
            {
                q.erase({dis[to], to});
                dis[to] = dis[node] + len;
                q.insert({dis[to], to});
            }
        }
    }

}

int main()
{
    int i, j;
    string s;
    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
            adj[i].clear();

        for(i = 2; i <= n; i++)
        {
            for(j = 1; j < i; j++)
            {
                cin >> s;
                if(s == "x")
                    continue;
                int c = stoi(s);
                adj[i].push_back({c, j});
                adj[j].push_back({c, i});
            }
        }

        dijkstra(1);

        int ans = 0;
        for(i = 2; i <= n; i++)
            ans = max(ans, dis[i]);

        cout << ans << endl;
    }
}
