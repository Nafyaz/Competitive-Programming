#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

bitset<200009> sp, vis;
int a[200009], dist[2][200009];
vector<int> adj[200009];

void bfs(int x, int src)
{
    dist[x][src] = 0;
    vis[src] = 1;

    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto u : adj[node])
        {
            if(!vis[u])
            {
                dist[x][u] = dist[x][node] + 1;
                q.push(u);
                vis[u] = 1;
            }
        }
    }
}


int main()
{
    int i, n, m, k, u, v, flag = 0;
    cin >> n >> m >> k;
    for(i = 0; i < k; i++)
    {
        cin >> a[i];
        sp[a[i]] = 1;
    }

    for(i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        if(sp[u] && sp[v])
            flag = 1;
    }

    vis = 0;
    bfs(0, 1);
    vis = 0;
    bfs(1, n);

    if(flag)
    {
        cout << dist[0][n];
        return 0;
    }

    vector<pair<int, int> > diff;
    for(i = 0; i < k; i++)
        diff.push_back({dist[0][a[i]] - dist[1][a[i]], a[i]});

    sort(diff.begin(), diff.end());

    int mxdistn[k + 1];
    mxdistn[k] = INT_MIN;
    for(i = k-1; i>= 0; i--)
        mxdistn[i] = max(mxdistn[i+1], dist[1][diff[i].ss]);

    int mx = -1;
    for(i = 0; i < k-1; i++)
        mx = max(mx, dist[0][diff[i].ss] + mxdistn[i+1] + 1);

    cout << min(mx, dist[0][n]);
}

/*
6 5 3

2 4 5

1 2

2 3

3 4

4 6

5 6
*/
