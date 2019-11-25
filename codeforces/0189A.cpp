#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, n, a[3], dp[5000];
    memset(dp, -1, sizeof(dp));

    cin >> n >> a[0] >> a[1] >> a[2];
    dp[0] = 0;

    for(i = 1; i <= n; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(i - a[j] >= 0 && dp[i - a[j]] != -1)
                dp[i] = max(dp[i], dp[i - a[j]] + 1);
        }
    }

    cout << dp[n];
}
