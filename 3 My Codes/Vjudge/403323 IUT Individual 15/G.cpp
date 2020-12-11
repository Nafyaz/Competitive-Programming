#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1234567

ll bigmod(ll a, ll b, ll mod)
{
    ll ret = 1%mod;
    while(b)
    {
        if(b&1)
            ret = (ret*a)%mod;

        a = (a*a)%mod;
        b = (b >> 1);
    }

    return ret;
}

int main()
{
    ll t, x, y, n, i;
    cin >> t;
    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> x >> y;

        if(n < 3)
            cout << 0 << "\n";
        else
        {
            ll ans = ((bigmod(2, n, MOD) - 1 - n - n*(n-1)/2)%MOD + MOD)%MOD;
            cout << ans << "\n";
        }
    }
}
