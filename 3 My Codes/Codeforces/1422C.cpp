#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll preSum1[100005];
ll preSum2[100005];

int main()
{
    ll i, n, ans, total, p, left, right;
    string s;

    cin >> s;
    n = s.size();

    for(i = 1; i <= n; i++)
    {
        preSum1[i] = (10*preSum1[i-1] + s[i-1] - '0') % mod;
        preSum2[i] = (preSum2[i-1] + preSum1[i]) % mod;
    }

    total = preSum1[n];
    ans = 0;
    p = 1;
    for(i = n; i >= 1; i--)
    {
        right = ((((total - preSum1[i]*p)%mod + mod)%mod) * i)%mod;
        left = (preSum2[i-1]*p) % mod;
        ans = (ans + left + right) % mod;
        p = (p*10) % mod;
    }

    cout << ans;
}
