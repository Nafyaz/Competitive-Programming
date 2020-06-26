#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n, m;
pair<int, int> dis[10009];
vector<pair<int, int>> adj[10009];

void init()
{
    for(int i = 0; i <= n; i++)
    {
        dis[i].ff = INT_MAX;
    }
}

void print(set<pair<pair<int, int>, int>> x)
{
    for(auto u : x)
        cout << u.ff.ff << " " << u.ff.ss << " " << u.ss << endl;
    cout << endl;
}

void dijkstra(int s)
{
    init();

    int node, to, len, hill;
    set<pair<pair<int, int>, int>> q;
    pair<pair<int, int>, int> temp;
    dis[s] = {0, -1};
    q.insert({{0, -1}, s});
    while(!q.empty())
    {
//        print(q);
        temp = *q.begin();
        hill = temp.ff.ss;
        node = temp.ss;
        q.erase(q.begin());
        for(auto u : adj[node])
        {
            to = u.ss;
            len = !(hill == -1 || hill == u.ff);

            if(dis[to].ff > dis[node].ff + len)
            {
                q.erase({dis[to], to});

                dis[to].ff = dis[node].ff + len;
                dis[to].ss = u.ff;

                q.insert({dis[to], to});
            }
            else if(dis[to].ff == dis[node].ff + len && dis[to].ss != u.ff)
            {
                dis[to].ff = dis[node].ff + len;
                dis[to].ss = u.ff;

                q.insert({dis[to], to});
            }
        }
    }
}

int main()
{
    int u, v, s, d, i;
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back({1, v});
        adj[v].push_back({0, u});
    }

    cin >> s >> d;
    dijkstra(s);

//    for(i = 0; i <= n; i++)
//        cout << i << " " << dis[i] << endl;

    cout << dis[d].ff;
}
/*
9 12
7 3
9 3
9 2
1 2
1 3
4 7
4 1
5 1
4 8
5 8
6 5
2 6
1 8
*/
