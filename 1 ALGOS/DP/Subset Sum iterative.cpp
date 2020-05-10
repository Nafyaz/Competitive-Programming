#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, n, s;
    cin >> n >> s;
    int a[n+1];
    a[0] = 0;
    for(i = 1; i <= n; i++)
        cin >> a[i];

    bool dp[n+1][s+1];

    for(i = 1; i <= s; i++)
        dp[0][i] = 0;
    for(i = 0; i <= n; i++)
        dp[i][0] = 1;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= s; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j >= a[i])
                dp[i][j] = dp[i][j] | dp[i-1][j - a[i]];
        }
    }

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= s; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
