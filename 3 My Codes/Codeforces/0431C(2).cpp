//follow ecnerwala
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k, d;
ll dp[102][2], MOD = 1000000007;

int main()
{
    cin >> n >> k >> d;

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k && j <= i; j++)
        {
            dp[i][1] = (dp[i][1] + dp[i-j][1])%MOD;
            if(j >= d)
                dp[i][1] = (dp[i][1] + dp[i-j][0])%MOD;
            else
                dp[i][0] = (dp[i][0] + dp[i-j][0])%MOD;
        }
    }

    cout << dp[n][1];
}
