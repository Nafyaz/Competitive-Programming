#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, l;
ll a[502], d[502];
ll dp[502][502];

ll call(ll i, ll k)
{
    if(i == n)
        return dp[i][k] = 0;

    if(dp[i][k] != -1)
        return dp[i][k];

    dp[i][k] = INT_MAX;
    for(ll skip = 0; skip <= k; skip++)
    {
        if(i + skip + 1 <= n)
            dp[i][k] = min(dp[i][k], (d[i+skip+1] - d[i])*a[i] + call(i+skip+1, k-skip));
    }

    return dp[i][k];
}

int main()
{
    ll k, i;

    cin >> n >> l >> k;

    for(i = 0; i < n; i++)
        cin >> d[i];
    d[n] = l;
    for(i = 0; i < n; i++)
        cin >> a[i];
    a[n] = 0;

//    cout << d[1]*a[0];

    memset(dp, -1, sizeof dp);
    if(n == 1)
        cout << l*a[0];
    else
        cout << call(0, k);
}
