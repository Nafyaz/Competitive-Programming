#include<bits/stdc++.h>
using namespace std;

int b[1003];
int coins[1003];
int cost[1003];

int operations[1003];
int dp[12003];

int main()
{
    freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k, i, j;

    for(i = 1; i < 1003; i++)
        operations[i] = INT_MAX;
    operations[1] = 0;

    for(i = 1; i < 1003; i++)
    {
        for(j = 1; j <= i; j++)
        {
            if(i+i/j < 1003)
                operations[i+i/j] = min(operations[i+i/j], operations[i]+1);
        }
    }

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        k = min(k, 12*n);

        for(i = 1; i <= n; i++)
            cin >> b[i];
        for(i = 1; i <= n; i++)
            cin >> coins[i];

        for(i = 1; i <= n; i++)
            cost[i] = operations[b[i]];

        for(i = 0; i <= k; i++)
            dp[i] = 0;

        for(i = 1; i <= n; i++)
        {
            for(j = k; j >= cost[i]; j--)
            {
                dp[j] = max(dp[j], coins[i] + dp[j-cost[i]]);
            }
        }

        cout << dp[k] << "\n";
    }
}
