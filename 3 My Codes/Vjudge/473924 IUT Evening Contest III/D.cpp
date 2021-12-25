#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll vector<pair<ll, ll>> adj[200005];

int main()
{
    ll n, i,

    cin >> n;

    for(i = 1; i < n; i++)
    {
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
}
