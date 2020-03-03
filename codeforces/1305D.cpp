#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define ff first
#define ss second

bitset<1009> ontree;
vector<int> adj[1009];

int main()
{
    int n, i, j, u, v;
    cin >> n;
    for(i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ontree[u] = ontree[v] = 1;
    }

    for(i = )
}
