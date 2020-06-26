#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, w[109], v[109], dp[109][100009], ans;

ll call(ll i, ll j)
{
    cout << i << " " << j << endl;
    if(j == 0)
        return dp[i][j] = 0;
    if(i == 0)
        return dp[i][j] = INT_MAX;
    if(dp[i][j] != -1)
        return dp[i][j];

    if(j < v[i])
        dp[i][j] = call(i-1, j);
    else
        dp[i][j] = min(call(i-1, j), call(i-1, j - v[i]) + w[i]);

    if(dp[i][j] <= m)
        ans = max(ans, j);

    return dp[i][j];
}

int main()
{
    ll i, j, sum = 0;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
        sum += v[i];
    }
    cout << "lol" << endl;

    memset(dp, -1, sizeof dp);

    call(n, sum);

    for(j = 0; j <= sum; j++)
        cout << setw(12) << j;
    cout << endl;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= sum; j++)
            cout << setw(12) << dp[i][j];
        cout << endl;
    }

    cout << ans;
}
/*
3 8
3 3
4 5
5 6
*/
