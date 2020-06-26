#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, i, h[100009], dp[100009];

    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> h[i];

    dp[0] = INT_MAX;
    dp[1] = 0;

    for(i = 2; i <= n; i++)
        dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));

    cout << dp[n];
}
