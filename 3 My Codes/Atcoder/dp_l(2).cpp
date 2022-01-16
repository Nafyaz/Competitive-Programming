#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[3003][3003];
ll a[3003];
ll pre[3003];

int main()
{
    ll n, i, len, st, ed;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }

    for(len = 1; len <= n; len++)
    {
        for(st = 1; st+len-1 <= n; st++)
        {
            ed = st+len-1;

            if(st == ed)
            {
                dp[st][ed] = a[st];
                continue;
            }

            ll left = dp[st][ed-1];
            ll right = dp[st+1][ed];

            dp[st][ed] = max(pre[ed]-pre[st-1] - left, pre[ed]-pre[st-1] - right);
        }
    }

    cout << 2*dp[1][n] - pre[n];
}
