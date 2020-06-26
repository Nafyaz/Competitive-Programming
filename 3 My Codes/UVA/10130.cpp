#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, g, i, j, ans;
    int p[1009], w[1009], dp[1009][35], mw;

    for(i = 0; i < 1009; i++)
            dp[i][0] = 0;
    for(i = 0; i < 35; i++)
        dp[0][i] = 0;

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> p[i] >> w[i];

        cin >> g;
        ans = 0;
        while(g--)
        {
            cin >> mw;
            for(i = 1; i <= n; i++)
            {
                for(j = 0; j <= mw; j++)
                {
                    if(j < w[i])
                        dp[i][j] = dp[i-1][j];
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + p[i]);
                }
            }

            ans += dp[n][mw];
        }

        cout << ans << endl;
    }
}
/*
2
3
72 17
44 23
31 24
1 26
*/
