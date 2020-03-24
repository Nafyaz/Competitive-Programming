#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (1LL<<60)

ll n, dp[100009][2], c[100009];
string s[100009][2];

ll func(ll i, ll j)
{
    if(i == n)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    ll ret = inf;
    if(i == 0 || s[i-1][j] <= s[i][0])
        ret = min(ret, func(i+1, 0));
    if(i == 0 || s[i-1][j] <= s[i][1])
        ret = min(ret, c[i] + func(i+1, 1));

    return dp[i][j] = ret;
}

int main()
{
    ll i, j;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> c[i];
    for(i = 0; i < n; i++)
    {
        cin >> s[i][0];
        s[i][1] = s[i][0];
        reverse(s[i][1].begin(), s[i][1].end());
        dp[i][0] = dp[i][1] = -1;
    }

    ll ans = func(0, 0);

    if(ans == inf)
        cout << -1;
    else
        cout << ans;
}
