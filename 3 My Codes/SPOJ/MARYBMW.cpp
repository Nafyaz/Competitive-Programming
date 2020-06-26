#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long

ll n, m, par[50009];
vector<pair<ll, pair<ll, ll> > > edge;

ll Find(ll a)
{
    if(par[a] == a)
        return a;
    return par[a] = Find(par[a]);
}

void Union(ll a, ll b)
{
    a = Find(a);
    b = Find(b);
    if(a != b)
        par[a] = b;
}

ll kruskal()
{
    ll i, u, v, w;
    for(i = 0; i <= n; i++)
        par[i] = i;

    sort(edge.begin(), edge.end(), greater<pair<ll, pair<ll, ll> > >());

    ll ret = LLONG_MAX;
    for(auto e : edge)
    {
        u = e.ss.ff;
        v = e.ss.ss;
        w = e.ff;
        if(Find(u) != Find(v))
        {
            Union(u, v);
            ret = min(ret, w);
            if(Find(1) == Find(n))
                return ret;
        }
    }
    return -1;
}

int main()
{
    ll t, i;
    scanf("%lld", &t);
    while(t--)
    {
        edge.clear();
        scanf("%lld %lld", &n, &m);
        for(i = 0; i < m; i++)
        {
            ll a, b, c;
            scanf("%lld %lld %lld", &a, &b, &c);
            edge.push_back({c, {a, b}});
        }
        printf("%lld\n", kruskal());
    }

}
