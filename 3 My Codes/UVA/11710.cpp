#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n, m, par[409];
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
    par[a] = b;
}

ll kruskal()
{
    ll i, ret = 0, cnt = 0;
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
            Union(u, v);
            ret += w;
            cnt++;
        }
    }
    if(cnt < n-1)
        return -1;
    else
        return ret;
}

int main()
{
    ll i, ans;
    while(1)
    {
        cin >> n >> m;
        if(!n && !m)
            break;
        edge.clear();
        map<string, ll> mp;
        string s, t;
        for(i = 1; i <= n; i++)
        {
            cin >> s;
            mp[s] = i;
        }
        for(i = 0; i < m; i++)
        {
            ll a, b, c;
            cin >> s >> t >> c;
            a = mp[s];
            b = mp[t];
            edge.push_back({c, {a, b}});
        }
        cin >> s;

        ans = kruskal();
        if(ans == -1)
            cout << "Impossible\n";
        else
            cout << ans << endl;
    }
}
/*
3 3
Picadilly
Victoria
Queensway
Picadilly Victoria 2
Queensway Victoria 10
Queensway Picadilly 20
Picadilly
4 2
Picadilly
Victoria
Queensway
Temple
Picadilly Victoria 2
Temple Queensway 100
Temple
0 0
*/
