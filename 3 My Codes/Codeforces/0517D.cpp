#include<bits/stdc++.h>
using namespace std;

double dp[2003][2003];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t, i, j;
    double p, ans;

    cin >> n >> p >> t;

    dp[0][0] = 1;
    for(i = 1; i <= t; i++)
    {
        dp[i][0] = dp[i-1][0]*(1-p);

        for(j = 1; j <= n; j++)
        {
            if(j != n)
                dp[i][j] = dp[i-1][j-1]*p + dp[i-1][j]*(1-p);
            else
                dp[i][j] = dp[i-1][j-1]*p + dp[i-1][j];
        }
    }

//    for(i = 0; i <= t; i++)
//    {
//        for(j = 0; j <= n; j++)
//            cout << setw(15) << dp[i][j];
//        cout << "\n";
//    }

    ans = 0;

    for(i = 1; i <= n; i++)
        ans += i*dp[t][i];

    cout << fixed << setprecision(7) << ans;
}
