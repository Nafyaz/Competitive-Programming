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

ll mulmod2(ll a, ll b, ll mod)
{
    ll res = 0;
    while(b)
    {
        if(b&1)
            res = (res + a)%mod;
        res = (res << 1)%mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    ll a, b, mod;
    cin >> a >> b >> mod;
    cout << mulmod2(a%mod, b%mod, mod);
}
