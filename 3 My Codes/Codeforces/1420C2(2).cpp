#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[300005], dp[300005][2];

int main()
{
    ll T, n, q, i;

    cin >> T;

    while(T--)
    {
        cin >> n >> q;

        for(i = 1; i <= n; i++)
            cin >> a[i];

        dp[0][0] = dp[0][1] = 0;
        for(i = 1; i <= n; i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - a[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + a[i]);
        }

        cout << max(dp[n][0], dp[n][1]) << "\n";
    }
}
