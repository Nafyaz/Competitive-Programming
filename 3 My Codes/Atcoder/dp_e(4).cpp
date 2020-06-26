#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, w[109], v[109], dp[109][100009];

ll call(ll pos, ll make)
{
    if(make == 0)
        return 0;
    if(pos == n)
        return INT_MAX;
    if(dp[pos][make] != -1)
        return dp[pos][make];

    dp[pos][make] = call(pos+1, make);
    if(make >= v[pos])
        dp[pos][make] = min(call(pos+1, make), call(pos+1, make - v[pos]) + w[pos]);

    return dp[pos][make];
}

int main()
{
    ll i, j, sum = 0, ans = 0;
    cin >> n >> m;
    for(i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
        sum += v[i];
    }

    memset(dp, -1, sizeof dp);

    for(i = 1; i <= sum; i++)
    {
        if(call(0, i) <= m)
            ans = max(ans, i);
    }

    cout << ans;
}
