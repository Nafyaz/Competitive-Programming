#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n, m, par[100009];
vector<pair<ll, pair<ll, ll> > > edge;

ll Find(ll a)
{
    if(a == par[a])
        return a;
    return par[a] = Find(par[a]);
}

void Union(ll a, ll b)
{
    a = Find(a);
    b = Find(b);
    par[a] = b;
}

ll kruskal()
{
    ll i, ret = 0;
    for(i = 0; i <= n; i++)
        par[i] = i;
    sort(edge.begin(), edge.end());
    for(auto e : edge)
    {
        ll u = e.ss.ff;
        ll v = e.ss.ss;
        ll w = e.ff;
        if(Find(u) != Find(v))
        {
            ret += w;
            Union(u, v);
        }
    }

    return ret;
}

int main()
{
    ll t, i;
    cin >> t;
    while(t--)
    {
        edge.clear();
        cin >> n >> m;
        for(i = 0; i < m; i++)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            c = log2(c);
            edge.push_back({c, {a, b}});
        }

        cout << kruskal()+1 << endl;
    }
}
