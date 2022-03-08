#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, t, n, f[16], mask, ans, sum;

    f[0] = 1;
    for(i = 1; i < 16; i++)
        f[i] = f[i-1] * i;

    map<ll, ll> factSum;
    for(mask = 0; mask < (1LL << 15); mask += 8)
    {
        sum = 0;
        for(i = 2; i < 16; i++)
        {
            if(mask & (1LL << i))
                sum += f[i];
        }

        if(factSum.find(sum) == factSum.end())
            factSum[sum] = __builtin_popcountll(mask);
        else
            factSum[sum] = min(factSum[sum], (ll)(__builtin_popcountll(mask)));
    }

    cin >> t;

    while(t--)
    {
        cin >> n;

        ans = LLONG_MAX;
        for(auto u : factSum)
            ans = min(ans, u.ss + __builtin_popcountll(n - u.ff));
        cout << ans << "\n";
    }

}
