#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, i, j, w[109], v[109], dp[109][100009];
int main()
{
    cin >> n >> m;

    for(i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    for(i = 0; i <= m; i++)
        dp[0][i] = 0;

    for(i = 1; i <= n; i++)
    {
        for(j = 0; j <= m; j++)
        {
            if(j < w[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
        }
    }

    cout << dp[n][m];
}
