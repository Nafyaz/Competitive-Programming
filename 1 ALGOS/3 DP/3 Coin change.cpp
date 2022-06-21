#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i, j;

    scanf("%d %d", &n, &m);

    int dp[n+10], c[m];

    for(i = 0; i <= n + 5; i++)
        dp[i] = INT_MAX;

    for(i = 0; i < m; i++)
        scanf("%d", &c[i]);

    dp[0] = 0;

    for(i = 1; i <= n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(i - c[j] >= 0)
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
        }
    }

    if(dp[n] != INT_MAX)
        printf("%d", dp[n]);
    else
        printf("%d is not possible", n);
}
