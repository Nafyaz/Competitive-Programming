#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

bitset<200009>sp(0);
int a[200009], dis[200009];
int par[200009];
vector<int> adj[200009];

int bfs(int src, int des, int type)
{
    par[src] = -1;
    dis[src] = 0;

    int node;
    queue<int> q;

    q.push(src);

    while(!q.empty())
    {
        node = q.front();
        q.pop();
        for(auto u : adj[node])
        {
            cout << "node: " << node << " u: " << u << endl;
            if(u == par[node])
                continue;
            if(u == des)
                return dis[node] + 1;
            if(type & sp[u])
                return u;

            q.push(u);
            par[u] = node;
            dis[u] = dis[node] + 1;

        }
    }
}


int main()
{
    int n, m, k, i, j;
    cin >> n >> m >> k;

    for(i = 0; i < k; i++)
    {
        cin >> a[i];
        sp[a[i]] = 1;
    }

    int u, v, flag = 0;

    while(m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        if(sp[u] == 1 && sp[v] == 1)
        {
            flag = 1;
        }
    }

    if(flag)
    {
        cout << bfs(1, n, 0);
        return 0;
    }

    int ans = -1;
    for(i = 0; i < k; i++)
    {
        u = a[i];
        v = bfs(u, -1, 1);
        cout <<"lol" <<  u << " " << v << endl;
        for(j = 1; j <= n; j++)
            cout << dis[j] << " ";
        cout << endl;

        adj[u].push_back(v);
        adj[v].push_back(u);

        cout << "ok" << endl;
        ans = max(ans, bfs(1, n, 0));
        cout << "ans: " << ans << endl;
        cout << "dis: " << endl;
        for(j = 1; j <= n; j++)
            cout << dis[j] << " ";
        cout << endl;

        adj[u].pop_back();
        adj[v].pop_back();
    }

    cout << ans;
}
