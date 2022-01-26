#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll fact[2000009];
ll dp[500][500];

ll f(ll n, ll mod)
{
    if(fact[n])
        return fact[n];
    if(n == 0 || n == 1)
        return 1;

    fact[n] = (n*f(n-1, mod))%mod;
    return fact[n];
}

ll bigmod(ll a, ll p, ll mod)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return a%mod;

    ll res = bigmod(a, p>>1, mod);
    res = (res*res)%mod;
    if(p&1)
        return (a*res)%mod;
    return res;
}

ll invmod(ll a, ll mod)
{
    return bigmod(a, mod-2, mod);
}

ll nCr(ll n, ll r, ll mod)
{
    if(n < r)
        return 0;
    return ((f(n, mod) * invmod(f(r, mod), mod))%mod * invmod(f(n-r, mod), mod))%mod;
}

ll nCr2(ll n, ll r, ll mod)
{
    if(n < r)
        return 0;

    if(dp[n][r] != 0)
        return dp[n][r];

    if(!r)
        return dp[n][r] = 1;

    return dp[n][r] = nCr2(n-1, r-1) + nCr2(n-1, r);
}
