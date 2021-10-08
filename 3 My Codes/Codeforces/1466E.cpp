#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll x[500005], p[64];

void solve()
{
    ll n, i, c, digsum[64] = {0}, sum = 0, AND, OR, ans = 0;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> x[i];

        sum = (sum + x[i]) % mod;

        for(c = 0; c < 64; c++)
            digsum[c] += (x[i] & (1LL << c)) >> c;
    }

    for(i = 0; i < n; i++)
    {
        AND = 0;

        for(c = 0; c < 64; c++)
            AND = (AND + (((x[i] & (1LL << c))%mod) * digsum[c]) %mod )%mod;

        OR = (((((n * (x[i]%mod)) % mod + sum) % mod) - AND)%mod + mod)%mod;

        ans = (ans + (AND * OR)%mod)%mod;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll t, i;

    p[0] = 1;

    for(i = 1; i < 64; i++)
    {
        p[i] = (p[i-1] << 1LL) % mod;
    }

    cin >> t;

    while(t--)
    {
        solve();
    }
}
