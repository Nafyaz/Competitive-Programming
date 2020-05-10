#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll fact[2000009];

ll f(ll n, ll m)
{
    if(fact[n])
        return fact[n];
    if(n == 0 || n == 1)
        return 1;

    fact[n] = (n*f(n-1, m))%m;
    return fact[n];
}

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

ll invmod(ll a, ll m)
{
    return bigmod(a, m-2, m);
}

ll nCr(ll n, ll r, ll m)
{
    return ((f(n, m) * invmod(f(r, m), m))%m * invmod(f(n-r, m), m))%m;
}
