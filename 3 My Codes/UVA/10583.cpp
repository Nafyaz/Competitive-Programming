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

int ans, parent[50000];

int Find(int x)
{
    if(parent[x] == x)
        return x;
    parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int u, int v)
{
    u = Find(u);
    v = Find(v);

    if(u != v)
    {
        parent[u] = v;
        ans--;
    }
}

int main()
{
    int n, m, i, u, v, caseno = 0;
    while(1)
    {
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;

        for(i = 0; i <= n; i++)
            parent[i] = i;

        ans = n;
        while(m--)
        {
            cin >> u >> v;
            Union(u, v);
        }

        cout<< "Case " << ++caseno << ": " << ans << endl;
    }
}
