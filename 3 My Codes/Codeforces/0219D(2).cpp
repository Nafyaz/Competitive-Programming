#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long

vector<pair<ll, ll>> adj[200005];
ll inverseInPath[200005];
ll directInPath[200005];

ll dfs(ll s, ll p)
{
    ll ret = 0;

    for(auto u : adj[s])
    {
        if(u.ss == p)
            continue;

        if(u.ff == 0)
            ret++;

        directInPath[u.ss] = directInPath[s] + (u.ff == 1);
        inverseInPath[u.ss] = inverseInPath[s] + (u.ff == 0);

        ret += dfs(u.ss, s);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, a, b, ans, totalInverse, inverseIfRoot;

    cin >> n;

    for(i = 1; i < n; i++)
    {
        cin >> a >> b;

        adj[a].push_back({1, b});
        adj[b].push_back({0, a});
    }

    totalInverse = dfs(1, -1);

    vector<ll> nodes;
    ans = totalInverse;
    nodes.push_back(1);

    for(i = 2; i <= n; i++)
    {
        inverseIfRoot = totalInverse - inverseInPath[i] + directInPath[i];

        if(inverseIfRoot < ans)
        {
            ans = inverseIfRoot;
            nodes.clear();
            nodes.push_back(i);
        }
        else if(inverseIfRoot == ans)
            nodes.push_back(i);
    }

    cout << ans << "\n";
    for(auto u : nodes)
        cout << u << " ";
}
