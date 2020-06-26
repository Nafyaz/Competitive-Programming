#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100009], mod = 1e9+7;

ll bigmod(ll b, ll p)
{
    if(p == 0)
        return 1;
    ll x = 1, y;
    if(p&1)
        x = b%mod;
    y = bigmod(b, p>>1);
    return ((y*y)%mod*x)%mod;
}



int main()
{
    ll n, k, i, j;
    cin >> n >> k;
    for(i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    ll p = 1, ans = a[k-1] - a[n-k];
    for(i = k; i <= n-1; i++)
    {
        p = (p*(i*bigmod(i-k+1, mod-2)%mod))%mod;
        ans = (ans + p*(a[i] - a[n - i - 1])%mod)%mod;
    }

    cout << (ans + mod)%mod;
}

