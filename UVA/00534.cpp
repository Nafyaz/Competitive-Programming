#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n;
double dis[209];
vector<pair<double, int>> adj[209];

void init()
{
    for(int i = 1; i <= n; i++)
        dis[i] = INT_MAX;
}

void dijkstra(int s)
{
    init();
    set<pair<double, int>> q;
    q.insert({0, s});
    dis[s] = 0;

    while(!q.empty())
    {
        int node = q.begin() -> ss;
        q.erase(q.begin());

        for(auto u : adj[node])
        {
            int to = u.ss;
            double len = u.ff;
            if(dis[to] > max(dis[node], len))
            {
                q.erase({dis[to], to});
                dis[to] = max(dis[node], len);
                q.insert({dis[to], to});
            }
        }
    }
}

int main()
{
    int i, j, x[209], y[209], t = 0;
    while(1)
    {
        cin >> n;
        if(!n)
            break;
        for(i = 1; i <= n; i++)
        {
            cin >> x[i] >> y[i];
            adj[i].clear();
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(i != j)
                    adj[i].push_back({sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])), j});
//                adj[j].push_back({sqrt((x[i] - x[j]) * (x[i] - x[j]) + sqrt((y[i] - y[j]) * (y[i] - y[j]))), i});
            }
        }

//        cout << adj[1][0].ff << " " << adj[1][0].ss << endl;
//        cout << adj[1][1].ff << " " << adj[1][1].ss << endl;

        dijkstra(1);
        cout << "Scenario #" << ++t << endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << dis[2] << endl << endl;
    }
}
/*
2
0 0
3 4

3
17 4
19 4
18 5

0
*/
