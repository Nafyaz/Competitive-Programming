#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
ll c[102];
ll dp[102][10004];

ll call(ll i, ll j)
{
    if(i > n)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = call(i+1, j);
    if(c[i]*(n-i+1) <= j)
        dp[i][j] = max(dp[i][j], 1 + call(i+1, j-c[i]*(n-i+1)));

    return dp[i][j];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll i, X;

    cin >> n >> X;

    for(i = 1; i <= n; i++)
        cin >> c[i];

    memset(dp, -1, sizeof dp);
    cout << call(1, X);
}
