#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll mulmod(ll a, ll b)
{
    if(b == 0)
        return 0;
    ll res = mulmod(a, b>>1);
    res = (res<<1)%mod;

    if(b&1)
        res = (res + a)%mod;
    return res;
}
ll bigmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    ll res = bigmod(a, b>>1);
    res = mulmod(res, res);

    if(b&1)
        res = mulmod(res, a);
    return res;
}
ll modinv(ll a)
{
    return bigmod(a, mod-2);
}

int main()
{
    ll a, b, n, x, an;
    cin >> a >> b >> n >> x;
    if(a == 1)
        cout << (x + mulmod(n, b))%mod;
    else
    {
        an = bigmod(a, n);
        cout << (mulmod(an, x) + mulmod(mulmod(an - 1, modinv(a-1)), b))%mod;
    }
}
