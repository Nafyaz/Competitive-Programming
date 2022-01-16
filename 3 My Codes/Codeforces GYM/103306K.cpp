#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mx 1000006

ll dp[mx], pw[mx];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, k, i, j, ans;

    pw[0] = 1;
    pw[1] = 2;
    for(i = 2; i < mx; i++)
    {
        pw[i] = (pw[i-1] * 2) % mod;
        dp[i] += pw[1];
    }

    for(i = 2; i < mx; i++)
    {
        for(j = 2*i; j < mx; j += i)
            dp[j] = ((dp[j] + pw[i] - dp[i]) % mod + mod) % mod;
    }

    cin >> t;

    while(t--)
    {
        cin >> k;

        cout << dp[k] << "\n";
    }
}
