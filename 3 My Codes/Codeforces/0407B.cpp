#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll dp[1003];
ll p[1003];

int main()
{
    ll n, i, j, ans = 0;

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> p[i];

    for(i = 1; i <= n; i++)
    {
        if(i == p[i])
            dp[i] = 1;
        else
        {
            dp[i] = 1;
            for(j = p[i]; j < i; j++)
                dp[i] = (dp[i] + dp[j] + 1) % mod;
        }

        ans = (ans + dp[i] + 1) % mod;
    }

    cout << ans;
}
