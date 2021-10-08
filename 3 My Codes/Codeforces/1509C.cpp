#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll s[2003], dp[2003][2003];

ll func(ll l, ll r)
{
    if(l > r)
        return LLONG_MAX;
    if(l == r)
        return 0;

    if(dp[l][r] != -1)
        return dp[l][r];

    return dp[l][r] = s[r] - s[l] + min(func(l, r-1), func(l+1, r));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll n, i;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> s[i];

    sort(s, s+n);

    memset(dp, -1, sizeof dp);

    cout << func(0, n-1);
}
