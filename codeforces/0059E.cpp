#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n, m, k;
set<pair<pair<int, int>, int>> forbidden;
int dis[3009][3009];
vector<int> adj[3009];

void init()
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
            dis[i][j] = INT_MAX;
    }
}

void dijkstra(int s)
{
    init();

    set<pair<pair<int, int>, int>> q;
    dis[s][s] = 0;
    q.insert({{dis[s][s], s}, s});

    pair<pair<int, int>, int> temp;

    while(!q.empty())
    {
        temp = *q.begin();
        q.erase(q.begin());
        int d = temp.ff.ff;
        int par = temp.ff.ss;
        int node = temp.ss;
        for(auto u : adj[node])
        {
            if(forbidden.find({{par, node}, u}) == forbidden.end() && dis[node][u] > d + 1)
            {
                q.erase({{dis[node][u], node}, u});
                dis[node][u] = d + 1;
                q.insert({{dis[node][u], node}, u});
            }

        }
    }
}

int main()
{
    int u, v, w, i;
    cin >> n >> m >> k;
    for(i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(i = 0; i < k; i++)
    {
        cin >> u >> v >> w;
        forbidden.insert({{u, v}, w});
    }

    dijkstra(1);

    int ans = INT_MAX;
    for(i = 0; i <= n; i++)
        ans = min(ans, dis[i][n]);

    if(ans == INT_MAX)
    {
        cout << -1;
        return 0;
    }

    cout << ans << endl;
    int node = n;
    stack<int> s;
    s.push(node);
    while(ans)
    {
        for(i = 0; i <= n; i++)
        {
            if(dis[i][node] == ans)
            {
                s.push(i);
                node = i;
                ans--;
                break;
            }
        }
    }
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
/*
4 4 4
1 2
2 3
3 4
1 3
1 2 3
1 3 4
1 2 4
1 3 2
*/
