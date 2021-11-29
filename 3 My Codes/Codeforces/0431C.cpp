#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k, d;
ll dp[102][2], MOD = 1000000007;

ll call(ll sum, ll taken)
{
    if(sum > n)
        return 0;
    if(sum == n)
        return taken;

    if(dp[sum][taken] != -1)
        return dp[sum][taken];

    ll ret = 0;
    for(ll i = 1; i <= k; i++)
    {
        if(i >= d || taken)
            ret = (ret + call(sum + i, 1)) % MOD;
        else
            ret = (ret + call(sum + i, 0)) % MOD;
    }

    return dp[sum][taken] = ret;
}

int main()
{
    cin >> n >> k >> d;

    memset(dp, -1, sizeof dp);
    cout << call(0, 0);
}
