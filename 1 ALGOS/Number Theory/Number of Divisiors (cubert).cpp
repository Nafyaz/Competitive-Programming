//Code doesn't work
//Need to fix

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000009

bool flag[N];
vector<ll> primes;

void sieve()
{
    ll i, j, val = sqrt(N) + 1;

    flag[0] = flag[1] = 1;

    for(i = 4; i < N; i += 2)
        flag[i] = 1;

    for(i = 3; i < val; i += 2)
    {
        if(!flag[i])
        {
            for(j = i*i; j < N; j += i)
                flag[j] = 1;
        }
    }

    for(i = 2; i < N; i++)
    {
        if(!flag[i])
            primes.push_back(i);
    }
}

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

ll NOD(ll n)
{
    ll i, c, sum = 1, x;

    for(i = 0; primes[i]*primes[i]*primes[i] <= n; i++)
    {
        for(c = 0; n%primes[i] == 0; c++)
            n /= primes[i];
        sum *= (c+1);
    }

    if(n == 1)
        return sum;
    if(Miller(n, 10))
        return sum << 1;
    x = sqrt(n);
    if(x*x == n && !flag[x])
        return sum*3;
    return sum << 2;
}
