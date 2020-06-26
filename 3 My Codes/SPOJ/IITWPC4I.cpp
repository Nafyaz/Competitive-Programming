#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n, m, par[100009], cnt[100009];
vector<pair<ll, pair<ll, ll> > > edge;

int Find(int a)
{
    if(par[a] == a)
        return a;
    return par[a] = Find(par[a]);
}
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    par[a] = b;
}

ll kruskal()
{
    sort(edge.begin(), edge.end());
    ll ret = 0;
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
    ll t, i, x;
    cin >> t;
    while(t--)
    {
        edge.clear();
        cin >> n >> m;
        for(i = 0; i <= n; i++)
        {
            par[i] = i;
            cnt[i] = 0;
        }
        for(i = 1; i <= n; i++)
        {
            cin >> x;
            if(x == 1)
                Union(0, i);
        }
        for(i = 0; i < m; i++)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            edge.push_back({c, {a, b}});
        }

        ll ans = kruskal();

        for(i = 1; i <= n; i++)
            cnt[Find(i)]++;

        if(cnt[Find(0)] < n)
            cout << "impossible\n";
        else
            cout << ans << endl;
    }
}
