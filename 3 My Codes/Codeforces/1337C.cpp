#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool ind[200009];
ll sz[200009], dist[200009];
vector<ll> adj[200009];
vector<ll> v;

int dfs(ll s, ll p)
{
    sz[s] = 1;
    for(auto u : adj[s])
    {
        if(u == p)
            continue;

        dist[u] = dist[s] + 1;
        sz[s] += dfs(u, s);
    }

    v.push_back(dist[s] - sz[s] +  1);

    return sz[s];
}

int main()
{
    ll n, k, a, b, i;

    cin >> n >> k;
    for(i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    sort(v.begin(), v.end(), greater<ll>());

    ll ans = 0, p;
    for(i = 0; i < k; i++)
        ans += v[i];


    cout << ans;
}
/*
7 5
1 2
1 3
1 4
3 5
3 6
4 7

*/
