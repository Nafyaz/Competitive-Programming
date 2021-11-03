#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, v, i, j, k;
    int dp[102][102];

    cin >> n >> v;

    for(i = 0; i <= v; i++)
        dp[1][i] = i;

    for(i = 2; i <= n; i++)
    {
        for(j = 0; j <= v; j++)
            dp[i][j] = INT_MAX;
        for(j = 0; j < v; j++)
        {
            dp[i][j] = min(dp[i][j], dp[i-1][j+1]);
            for(k = j+1; k <= v; k++)
                dp[i][k] = min(dp[i][k], dp[i][j] + i*(k-j));
        }
    }

    cout << dp[n][0];
}
