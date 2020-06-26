#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, i, j, k, len, m[109], pre[109], dp[109][109];

    pre[0] = 0;
    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
        {
            cin >> m[i];
            pre[i] = pre[i-1] + m[i];
        }

        memset(dp, 0, sizeof(dp));
        for(len = 2; len <= n; len++)
        {
            for(i = 1; i + len - 1 <= n; i++)
            {
                j = i + len - 1;
                dp[i][j] = INT_MAX;
                for(k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + ((pre[k] - pre[i-1])%100) * ((pre[j] - pre[k])%100));
            }
        }

        cout << dp[1][n] << endl;
    }
}
