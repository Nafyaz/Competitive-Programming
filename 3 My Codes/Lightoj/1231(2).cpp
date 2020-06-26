#include<bits/stdc++.h>
using namespace std;

int n, k, dp[55][1009], a[55], c[55];

int call(int i, int rem)
{
    if(rem == 0)
        return 1;
    if(i == n)
        return 0;

    if(dp[i][rem] != -1)
        return dp[i][rem];

    dp[i][rem] = 0;
    for(int l = 0; l <= c[i] && rem >= l*a[i]; l++)
        dp[i][rem] = (dp[i][rem] + call(i+1, rem-l*a[i]))%100000007;

    return dp[i][rem];
}

int main()
{
    int t, i, caseno = 0;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        memset(dp, -1, sizeof dp);

        for(i = 0; i < n; i++)
            cin >> a[i];
        for(i = 0; i < n; i++)
            cin >> c[i];

        cout << "Case " << ++caseno << ": " << call(0, k) << endl;
    }
}
