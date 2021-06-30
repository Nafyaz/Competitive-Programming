#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, w, k, i, j, x, y[109] = {0}, cnt[109], caseno = 0;
    int dp[109][109];

    cin >> t;
    while(t--)
    {
        cin >> n >> w >> k;
        for(i = 1; i <= n; i++)
            cin >> x >> y[i];
        sort(y+1, y+n+1);

        memset(cnt, 0, sizeof cnt);

        for(i = 1; i <= n; i++)
        {
            for(j = i; j <= n; j++)
            {
                if(y[j] <= y[i] + w)
                    cnt[i]++;
            }
        }

//        for(i = 0; i <= n; i++)
//            cout << cnt[i] << " ";

        memset(dp, 0, sizeof dp);

        for(j = 1; j <= k; j++)
        {
            for(i = 1; i <= n; i++)
            {
                dp[i][j] = dp[i-1][j];
                if(i >= cnt[i-1])
                    dp[i][j] = max(dp[i][j], dp[i-cnt[i-1]][j-1] + cnt[i]);
            }
        }

        cout << "Case " << ++caseno << ": " << dp[n][k] << "\n";
    }
}
