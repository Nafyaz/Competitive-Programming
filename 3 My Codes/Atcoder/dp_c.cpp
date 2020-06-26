#include<bits/stdc++.h>
using namespace std;

int n, i, j, k, a, b, c, dp[100009][3];

int main()
{
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a;
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b;
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c;
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]});
}
