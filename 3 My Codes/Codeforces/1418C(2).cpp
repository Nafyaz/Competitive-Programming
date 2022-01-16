#include<bits/stdc++.h>
using namespace std;

int a[200005];
int dp[200005][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, i;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
            cin >> a[i];

        dp[1][0] = a[1];        dp[1][1] = a[1];
        dp[2][0] = dp[1][0];    dp[2][1] = dp[1][1] + a[2];

        for(i = 3; i <= n; i++)
        {
            dp[i][0] = min(dp[i-1][1], dp[i-2][1]);
            dp[i][1] = min(dp[i-1][0]+a[i], dp[i-2][0]+a[i-1]+a[i]);
        }

        cout << min(dp[n][0], dp[n][1]) << "\n";
    }
}
