#include<bits/stdc++.h>
using namespace std;

double p[3009], dp[3009][3009];

int main()
{
    int n, i, j;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> p[i];

    dp[0][0] = 1;
    for(i = 1; i <= n; i++)
        dp[i][0] = dp[i-1][0] * (1 - p[i]);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
            dp[i][j] += dp[i-1][j-1]*p[i] + dp[i-1][j]*(1 - p[i]);
    }

//    for(i = 0; i <= n; i++)
//    {
//        for(j = 0; j <= n; j++)
//            cout << setw(5) << dp[i][j] << " ";
//        cout << endl;
//    }

    double ans = 0;
    for(i = n/2 + 1; i <= n; i++)
        ans += dp[n][i];

    cout << fixed << setprecision(9) << ans;
}
