//Code doesn't work
//Need to fix

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll mulmod(ll a, ll b, ll mod)
{
    if(b == 0)
        return 0;
    ll res = mulmod(a, b>>1, mod);
    res = (res<<1)%mod;
    if(b&1)
        return (res+a)%mod;
    else
        return res;
}

ll bigmod(ll a, ll b, ll mod)
{
    if(b == 0)
        return 1;
    ll res = bigmod(a, b>>1, mod);
    res = (res*res)%mod;
    if(b&1)
        return (a*res)%mod;
    return res;
}

bool Miller(ll p,int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2==0)
    {
        return false;
    }
    ll s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = bigmod(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return false;
        }
    }
    return true;
}

