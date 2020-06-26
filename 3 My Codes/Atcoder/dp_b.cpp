#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k, i, j, h[100009], dp[100009];
    cin >> n >> k;
    for(i = 1; i <= n; i++)
        cin >> h[i];

    dp[1] = 0;
    for(i = 2; i <= n; i++)
    {
        dp[i] = INT_MAX;
        for(j = 1; j <= k && i-j > 0; j++)
            dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
    }

    cout << dp[n];
}
