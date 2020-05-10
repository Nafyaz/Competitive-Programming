#include<bits/stdc++.h>
using namespace std;
#define ll long long

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
ll bigmod2(ll a, ll b, ll mod)
{
    ll res = 1%mod;
    while (b)
    {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

ll invmod(ll a, ll m)
{
    return bigmod(a, m-2, m);
}
