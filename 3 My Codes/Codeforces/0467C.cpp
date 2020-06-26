#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll p[5009], pre[5009], dp[5009][5009];

int main()
{
    ll n, m, k, i, j;
    cin >> n >> m >> k;

    for(i = 1; i <= n; i++)
    {
        cin >> p[i];
        pre[i] = pre[i-1] + p[i];
    }

    for(i = 1; i <= k; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(j < m*i)
                dp[i][j] = 0;
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j-m] + pre[j] - pre[j-m]);
        }
    }

    cout << dp[k][n];
}
