#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll parent[100010];
vector <pair<ll, pair<ll, ll> > >edges;

ll find(ll u)
{
    if(parent[u] == u)
        return parent[u];
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

    for(ll i = 0; i < 100010; i++)
    {
        parent[i] = i;
    }
    ll cost = 0;

    for(auto p : edges)
    {
        if(find(p.ss.ff) != find(p.ss.ss))
        {
            merge(p.ss.ff, p.ss.ss);
            cost += p.ff;
        }
    }
    return cost;
}

int main()
{
    ll u, v, w, n, m;
    scanf("%lld %lld", &n, &m);
    while(m--)
    {
        scanf("%lld %lld %lld", &u, &v, &w);
        edges.push_back({w, {u, v}});
    }

    printf("%lld", kruskal());
}

