#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

#define MOD 998244853

map<pair<ll, ll>, vector<ll>> roads;
vector<ll> path;

ll bigmod(ll a, ll p, ll m)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return a%m;
    ll x = 1;
    if(p&1)
        x = a%m;
    ll y = bigmod(a, p/2, m);
    return ((y*y)%m*x)%m;
}

ll invmod(ll a, ll m)  //only if m is prime and gcd(a, m) = 1
{
    return bigmod(a, m-2, m);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll n, m, k, i, u, v, w, a, b, flag, ans, pow;

    cin >> n >> m >> k;

    for(i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        roads[{u, v}].push_back(w);
        roads[{v, u}].push_back(w);
    }

    for(i = 0; i < k; i++)
    {
        cin >> a;
        path.push_back(a);
    }

    ans = 0;
    flag = 1;
    pow = 1;
    for(i = k-1; i > 0; i--)
    {
        u = path[i-1];
        v = path[i];

        if(roads[{u, v}].empty())
        {
            flag = 0;
            break;
        }

        a = 0;
        for(auto val : roads[{u, v}])
            a += val;

        b = roads[{u, v}].size();

        ans = (ans + (((a*invmod(b, MOD))%MOD)*pow)%MOD)%MOD;

        pow = (pow * 10)%MOD;
    }

    if(!flag)
        cout << "Stupid Msacywy!";
    else
        cout << ans;
}
