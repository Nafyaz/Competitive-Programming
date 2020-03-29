#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i, j;
    cin >> n >> m;
    int w[n+1], p[n+1], dp[n+1][m];

    for(i = 1; i <= n; i++)
        cin >> w[i] >> p[i];

    for(i = 0; i <= m; i++)
        dp[0][i] = 0;

    for(i = 1; i <= n; i++)
    {
        for(j = 0; j <= m; j++)
        {
            if(j < w[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], p[i] + dp[i-1][j-w[i]]);
        }
    }

    cout << dp[n][m];
}
