#include<bits/stdc++.h>
using namespace std;

int n, h, l, r;

int main()
{
    cin >> n >> h >> l >> r;
    int i, j, a[n+1], dp[n+1][n+1];
    a[0] = 0;

    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i-1];
    }

    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= i; j++)
        {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + (int)((a[i+1] - j)%h >= l && (a[i+1] - j)%h <= r));
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + (int)((a[i+1] - j - 1)%h >= l && (a[i+1] - j - 1)%h <= r));
        }
    }

    int ans = -1;
    for(i = 0; i <= n; i++)
        ans = max(ans, dp[n][i]);

    cout << ans;
}
