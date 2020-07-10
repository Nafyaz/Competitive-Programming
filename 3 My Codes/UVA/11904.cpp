#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define N 1000009

ll fact[N];

ll bigmod(ll a, ll p)
{
    ll ret = 1;
    while(p)
    {
        if(p&1)
            ret = (ret * a) % mod;
        a = (a * a) % mod;
        p >>= 1;
    }
    return ret;
}

ll invmod(ll n)
{
    return bigmod(n%mod, mod-2);
}

int main()
{
    ll T, caseno = 0, n, i, unit, ans, total;

    fact[0] = 1;
    for(i = 1; i < N; i++)
        fact[i] = (fact[i-1] * i) % mod;

    cin >> T;
    while(T--)
    {
        total = 0;
        cin >> n;
        ans = invmod(fact[n]);
        for(i = 0; i < n; i++)
        {
            cin >> unit;
            ans = (ans * invmod(fact[unit])) % mod;
            total += unit;
        }

        ans = (ans * fact[total]) % mod;

        cout << ans << endl;
    }
}
