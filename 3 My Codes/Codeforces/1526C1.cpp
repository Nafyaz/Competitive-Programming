#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[2003][2003];

int main()
{
    ll n, i, j, a[2003], ans;

    cin >> n;

    for(i = 1; i < 2003; i++)
        dp[0][i] = -1;

    for(i = 1; i <= n; i++)
    {
        cin >> a[i];

        for(j = 1; j <= n; j++)
        {
            if(i < j)
                dp[i][j] = -1;
            else
            {
                if(dp[i-1][j-1] < 0 && dp[i-1][j] < 0)
                    dp[i][j] = -1;
                else
                    dp[i][j] = max(dp[i-1][j-1] + a[i], dp[i-1][j]);
            }
        }
    }

    ans = n;
    while(dp[n][ans] < 0)
        ans--;

    cout << ans << "\n";
}
