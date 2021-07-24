#include<bits/stdc++.h>
using namespace std;

int grid[109][109];
int dp[109][109][109];

int main()
{
    int T, caseno = 0, m, n, i, j, k;

    cin >> T;

    while(T--)
    {
        cin >> m >> n;

        for(i = 1; i <= m; i++)
        {
            for(j = 1; j <= n; j++)
                cin >> grid[i][j];
        }

        memset(dp, -1, sizeof dp);

        dp[1][1][2] = grid[1][1] + grid[1][2];

        for(k = 3; k <= n; k++)
            dp[1][1][k] = dp[1][1][k-1] + grid[1][k];

        for(i = 2; i <= m; i++)
        {
            for(j = 1; j <= n-1; j++)
            {
                for(k = j+1; k <= n; k++)
                {
                    if((i == 2 && j == 1) || (i == m && k == n) || (i > 2 && i < m))
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + grid[i][j] + grid[i][k]);
                }
            }

            for(j = 2; j <= n-1; j++)
            {
                for(k = j+1; k <= n; k++)
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k] + grid[i][j]);
            }

            for(j = 1; j <= n-1; j++)
            {
                for(k = j+1; k <= n; k++)
                {
                     if(i < m && k > j+1)
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1] + grid[i][k]);
                }
            }
        }


        cout << "Case " << ++caseno << ": " << dp[m][n-1][n] << "\n";
    }
}
