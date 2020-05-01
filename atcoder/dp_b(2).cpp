#include<bits/stdc++.h>
using namespace std;

int n, k, h[100009], dp[100009];

int call(int i)
{
    if(i == n-1)
        return dp[i] = 0;

    if(dp[i] != -1)
        return dp[i];

    dp[i] = INT_MAX;
    for(int j = 1; j <= k && i+j < n; j++)
        dp[i] = min(dp[i], call(i+j) + abs(h[i]-h[i+j]));

    return dp[i];
}

int main()
{
    int i;
    cin >> n >> k;

    for(i = 0; i < n; i++)
        cin >> h[i];

    memset(dp, -1, sizeof dp);
    cout << call(0);
}
