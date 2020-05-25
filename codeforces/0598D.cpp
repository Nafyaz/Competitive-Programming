#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n, m;
string grid[1009];
map<pair<ll, ll>, ll> mp;
map<pair<ll, ll>, pair<ll, ll>> par;
ll dirx[4] = {-1, 0, 1, 0};
ll diry[4] = {0, 1, 0, -1};

pair<ll, ll> Find(pair<ll, ll> a)
{
    if(par.find(a) == par.end() || par[a] == a)
        return par[a] = a;
    return par[a] = Find(par[a]);
}

void Union(pair<ll, ll> a, pair<ll, ll> b)
{
    a = Find(a);
    b = Find(b);
    if(a != b)
        par[a] = b;
}

ll check(pair<ll, ll> a)
{
    if(a.ff < 0 || a.ff >= n || a.ss < 0 || a.ss >= m || grid[a.ff][a.ss] == '*')
        return 0;
    return 1;
}

ll dfs(pair<ll, ll> v)
{
    if(mp.find(v) != mp.end())
        return mp[Find(v)];
    mp[v] = 0;
    ll i;
    pair<ll, ll> u;
    for(i = 0; i < 4; i++)
    {
        u = {v.ff+dirx[i], v.ss+diry[i]};
        if(check(u))
        {
            Union(u, v);
            dfs(u);
        }
        else
            mp[Find(v)]++;
    }
    return mp[Find(v)];
}

int main()
{
    ll k, i, a, b;
    cin >> n >> m >> k;
    for(i = 0; i < n; i++)
        cin >> grid[i];

    for(i = 0; i < k; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        pair<ll, ll> v = {a, b};
        cout << dfs(v) << endl;
    }
}
