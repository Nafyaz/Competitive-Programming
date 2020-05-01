#include<bits/stdc++.h>
using namespace std;

long long n, h[100009], dp[100009];

long long call(long long i)
{
    if(i >= n)
        return 0;
    if(dp[i] != -1)
        return dp[i];

    dp[i] = INT_MAX;
    if(i < n)
        dp[i] = min(dp[i], call(i+1) + abs(h[i]-h[i+1]));
    if(i < n-1)
        dp[i] = min(dp[i], call(i+2) + abs(h[i]-h[i+2]));

    return dp[i];
}

int main()
{
    long long i;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> h[i];

    memset(dp, -1, sizeof dp);
    cout << call(1);
}
