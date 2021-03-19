#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll bigmod(ll a, ll b, ll mod)
{
    if(b == 0)
        return 1%mod;
    if(b == 1)
        return a%mod;

    ll res = bigmod(a, b>>1, mod);
    res = (res*res)%mod;
    if(b&1)
        return (a*res)%mod;
    return res;
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

int main()
{
    ll a, b, mod;
//    cin >> a >> b >> mod;
    cout << bigmod2(7, 5*29, 91);
}
