#include<bits/stdc++.h>
using namespace std;

int dp[101][50000];

int main()
{
    int t, n, i, j, p, total, w[101];
    cin >> t;
    while(t--)
    {
        cin >> n;
        total = 0;
        for(i = 1; i <= n; i++)
        {
            cin >> w[i];
            total += w[i];
        }
        for(i = 0; i <= total/2; i++)
            dp[0][i] = 0;
        for(i = 0; i <= n; i++)
            dp[i][0] = 0;

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= total/2; j++)
            {
                if(j < w[i])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j], w[i] + dp[i-1][j-w[i]]);
//                cout << dp[i][j] << " ";
            }
//            cout << endl;
        }

        cout << abs(total - 2*dp[n][total/2]) << endl;
    }
}
