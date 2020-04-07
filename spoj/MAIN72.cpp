#include<bits/stdc++.h>
using namespace std;

bool dp[109][100009];
int n, total, a[109], ans;

int main()
{
    int t, i, j;
    cin >> t;
    while(t--)
    {
        cin >> n;
        total = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            total += a[i];
            dp[i][0] = 1;
        }

        for(i = 0; i < n; i++)
        {
            for(j = 1; j <= total; j++)
            {
                dp[i][j] = 0;
                if(i == 0 && j == a[i])
                    dp[i][j] = 1;

                if(i > 0)
                {
                    dp[i][j] = dp[i-1][j];
                    if(j >= a[i])
                        dp[i][j] = dp[i][j] | dp[i-1][j-a[i]];
                }
            }
        }

//        for(i = 0; i < n; i++)
//        {
//            for(j = 0; j <= total; j++)
//                cout << dp[i][j] << " ";
//            cout << endl;
//        }
        ans = 0;
        for(i = 0; i <= total; i++)
            ans += (dp[n-1][i]? i : 0);
        cout << ans << endl;
    }
}
