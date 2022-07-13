ll dp[MAXN][MAXN];

void editDistance(string a, string b)
{
    ll i, j, n, m;

    n = a.size(), m = b.size();
    
    memset(dp, 0, sizeof dp);

    for(i = 1; i <= n; i++)
        dp[i][0] = i;
    for(j = 1; j <= m; j++)
        dp[0][j] = j;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
            if(a[i] == b[j])
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            else
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 2);
        }
    }

    cout << dp[n][m];
}
