#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll bigmod(ll a, ll b, ll mod)
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

ll call(ll a, ll n, ll mod)
{
    if(n == 1)
        return 1;
    ll ret1 = call(a, n/2, mod);
    ll ret2 = (bigmod(a, n/2, mod) * ret1)%mod;

    if(n%2 == 0)
        return (ret1 + ret2)%mod;
    else
        return ((ret1 + ret2)%mod + bigmod(a, n-1, mod))%mod;
}

int main()
{
    vector<pair<int, int>> v;

    pair<int, int> a[] = {{ 501,502}, {503, 504} };
    v.insert(v.begin(), a, a+3);

    for(auto u : v)
        cout << u.first << " " << u.second << "\n";

    pair<int, int> a[] = {{ 505,506}, {507, 508} };
    v.insert(v.begin(), a, a+3);
}
