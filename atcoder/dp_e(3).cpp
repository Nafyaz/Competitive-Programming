#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, w[109], v[109], dp[109][100009], ans;

ll call(ll i, ll j)
{
    if(i == n)
        return INT_MAX;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(call(i+1, j+v[i]) + w[i] > m)
        dp[i][j] = call(i+1, j);
    else
        dp[i][j] = min(call(i+1, j), w[i] + call(i+1, j+v[i]));
    if(dp[i][j] != -1)
        ans = max(ans, j);
    return dp[i][j];
}

int main()
{
    ll i, j;
    cin >> n >> m;
    for(i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    memset(dp, -1, sizeof dp);

    call(0, 0);
    cout << ans;
}
