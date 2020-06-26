#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, w[109], v[109], dp[109][100009];

ll call(ll i, ll j)
{
    if(i == 0)
        return 0;
    if(dp[i][j] != 0)
        return dp[i][j];
    if(j < w[i])
        dp[i][j] = call(i-1, j);
    else
        dp[i][j] = max(call(i-1, j), call(i-1, j-w[i]) + v[i]);
    return dp[i][j];
}

int main()
{
    ll i;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    cout << call(n, m);
}
