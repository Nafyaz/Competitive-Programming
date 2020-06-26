#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define N 200010
ll n, m;
vector< pair<ll, pair< ll, ll> > > edges;
ll parent[N];

ll find(int u)
{
    if(parent[u] == u)
        return u;
    parent[u] = find(parent[u]);
    return parent[u];
}

void merge(ll u, ll v)
{
    parent[find(u)] = find(v);
}

ll kruskal()
{
    sort(edges.begin(), edges.end());

    for(ll i = 1; i < N; i++)
        parent[i] = i;

    ll cost = 0;
    pair<ll, pair< ll, ll> > p;

    for(ll i = 0; i < edges.size(); i++)
    {
        p = edges[i];
        if(find(p.ss.ff) != find(p.ss.ss))
        {
            merge(p.ss.ff, p.ss.ss);
            cost = cost + p.ff;
        }
    }
    return cost;
}

int main()
{
    long long u, v, w;
    scanf("%lld %lld", &n, &m);
    long long mn = LLONG_MAX, i, a[n+1], mnv;
    for(i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        if(mn > a[i])
        {
            mn = a[i];
            mnv = i;
        }
    }

    for(i = 0; i < m; i++)
    {
        scanf("%lld %lld %lld", &u, &v, &w);
        edges.push_back({w, {u, v}});
    }

    for(i = 1; i <= n; i++)
    {
        if(i == mnv)
            continue;
        edges.push_back({a[i] + a[mnv], {i, mnv}});
    }

    printf("%lld", kruskal());

}
