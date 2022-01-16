#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll dp[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, i, m, ans;
    string n;

    for(i = 0; i <= 8; i++)
        dp[i] = 2;
    dp[9] = 3;
    for(i = 10; i < 200005; i++)
        dp[i] = (dp[i-9] + dp[i-10]) % mod;

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        ans = 0;
        for(i = 0; i < n.size(); i++)
            ans = (ans + (m + n[i]-'0' < 10? 1 : dp[m+n[i]-'0'-10])) % mod;

        cout << ans << "\n";
    }
}
