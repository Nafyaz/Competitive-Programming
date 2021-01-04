#include<bits/stdc++.h>
using namespace std;

int w[260], sum[260];
int dp[260][260];

int main()
{
    int n, i, j, dia, k;

    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
        {
            cin >> w[i];
            sum[i] = sum[i-1] + w[i];
        }

        memset(dp, 0, sizeof dp);
        for(dia = 1; dia <= n; dia++)
        {
            for(i = 1; i+dia-1 <= n; i++)
            {
                j = i+dia-1;
                dp[i][j] = INT_MAX;
                for(k = i; k <= j; k++)
                {
                    dp[i][j] = min(dp[i][j], (sum[j] - sum[i-1] - w[k]) + dp[i][k-1] + dp[k+1][j]);
                }
            }
        }

        cout << dp[1][n] << "\n";
    }
}

