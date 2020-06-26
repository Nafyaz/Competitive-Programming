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

int n, m, k, color[500009], flag = 1;
vector<int> adj[500009];
bitset<500009> b[500009];

void func(int s)
{
    int i;
    for(i = 0; ; i++)
    {
        if(b[s][i] == 0)
            break;
    }
    if(i >= k)
    {
        flag = 0;
        return;
    }

    b[s].set(i);
    color[s] = i+1;

    for(auto u : adj[s])
    {
        b[u].set(i);
    }
}

int main()
{
    int u, v, i;
    cin >> n >> m >> k;
    while(m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(i = 1; i <= n; i++)
    {
        if(flag == 0)
        {
            cout << -1;
            return 0;
        }

        func(i);
    }

    for(i = 1; i <= n; i++)
    {
        cout << color[i] << endl;
    }
}
