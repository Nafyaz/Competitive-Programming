#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, i, j, w[109], v[109], dp[109][100009];
int main()
{
    cin >> n >> m;

    for(i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    for(i = 0; i <= n; i++)
    {
        for(j = 1; j < 100009; j++)
            dp[i][j] = INT_MAX;
    }
    for(i = 0; i <= n; i++)
        dp[i][0] = 0;

    ll ans = 0;
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j < 100009; j++)
        {
            if(j < v[i] || dp[i-1][j-v[i]] + w[i] > m)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]] + w[i]);

            if(dp[i][j] != INT_MAX)
                ans = max(ans, j);
        }
    }

    cout << ans;
}
