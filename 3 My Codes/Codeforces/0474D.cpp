#include<bits/stdc++.h>
using namespace std;

int dp[100009], pre[100009], mod = 1e9+7;

int main()
{
    int t, k, i, a, b;
    cin >> t >> k;

    dp[0] = pre[0] = 1;

    for(i = 1; i < 100009; i++)
    {
        dp[i] = (dp[i] + dp[i-1])%mod;
        if(i >= k)
            dp[i] = (dp[i] + dp[i-k])%mod;
        pre[i] = (pre[i-1] + dp[i])%mod;
    }

    while(t--)
    {
        cin >> a >> b;
        cout << (pre[b] - pre[a-1] + mod)%mod << endl;
    }
}
