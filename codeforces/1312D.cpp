#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353

ll fact[200009];

ll findfact()
{
    fact[0] = fact[1] = 1;
    for(ll i = 2; i < 200009; i++)
        fact[i] = (fact[i-1] * i) % mod;
}

ll bigmod(ll a, ll p)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return a%mod;

    ll x = 1, y;
    if(p&1)
        x = a;

    y = bigmod(a, p>>1);

    return ((y*y)%mod * x)%mod;
}

ll inv(ll a)
{
    return bigmod(a, mod-2);
}

ll nCr(ll n, ll r)
{
    return ((fact[n] * inv(fact[r])) % mod * inv(fact[n-r]))%mod;
}

int main()
{
    ll n, m;

    cin >> n >> m;

    if(n == 2)
    {
        cout << 0;
        return 0;
    }

    findfact();


    cout << (((n-2) * bigmod(2, n-3))%mod * nCr(m, n-1))%mod;
}
