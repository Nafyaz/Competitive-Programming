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

int parent[1000009], n;
vector<pair<int, pair<int, int> > >edges;

int Find(int u)
{
    if(parent[u] == u)
        return u;
    parent[u] = Find(parent[u]);
    return parent[u];
}

void Union(int u, int v)
{
    int x = Find(u), y = Find(v);
    parent[x] = y;
}

int kruskal()
{
    int i, u, v, w, ret = 0;
    for(i = 0; i <= n; i++)
        parent[i] = i;
//    for(i = 0; i <= n; i++)
//        cout << parent[i] << " ";
//    cout << endl;
    sort(edges.begin(), edges.end());
    for(i = 0; i < edges.size(); i++)
    {
        u = edges[i].ss.ff;
        v = edges[i].ss.ss;
        w = edges[i].ff;
//        cout << u << ": " << Find(u) << " " << v << ": " << Find(v) << endl;

        if(Find(u) != Find(v))
        {
            Union(u, v);
            ret += w;
        }
    }

    return ret;
}

int main()
{
    int k, i, m, u, v, w, ans, cnt = 0;
    while(cin >> n)
    {
        if(cnt != 0)
        {
            cout << endl;
        }
        cnt++;
//        cout << n << endl;
        edges.clear();
        ans = 0;
        for(i = 0; i < n-1; i++)
        {
            cin >> u >> v >> w;
            ans += w;
        }
        cout << ans << endl;
        cin >> k;
        for(i = 0; i < k; i++)
        {
            cin >> u >> v >> w;
            edges.push_back({w, {u, v}});
        }
        cin >> m;
        for(i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            edges.push_back({w, {u, v}});
        }

        cout << kruskal() << endl;
    }
}
/*
5
1 2 5
1 3 5
1 4 5
1 5 5
1
2 3 2
6
1 2 5
1 3 5
1 4 5
1 5 5
3 4 8
4 5 8
*/
