#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll p = 31, mod = 1e9+9, invp = 838709685;

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
//    string x(2, 'A');

//    cout << bigmod2(p, mod-2, mod);

    pair<ll, ll> ans (3, 5);

    ans = {20, 3};

    cout << ans.first << " " << ans.second;
}
