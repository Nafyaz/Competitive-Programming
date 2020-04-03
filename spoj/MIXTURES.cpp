#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll m[109], pre[109], dp[109][109];

ll call(ll i, ll j)
{
    if(i >= j)
        return dp[i][j] = 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    ll k, ret = INT_MAX;
    for(k = i; k < j; k++)
        ret = min(ret, call(i, k) + call(k+1, j) + ((pre[k] - pre[i-1])%100) * ((pre[j] - pre[k])%100));

    return dp[i][j] = ret;
}

int main()
{
    ll n, i, j;
    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
        {
            cin >> m[i];
            pre[i] = pre[i-1] + m[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << call(1, n) << endl;
    }
}
