#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define inf IN
ll n, k, a[1000009], dp[1000009], par[1000009];

ll frd(ll i)
{
    if(i >= n)
    return 0;

    if(dp[i] != INT_MIN)
        return dp[i];

    ll ret = 0, p1 = frd(i+1), p2 = frd(i+2);
    if(ret < p1)
    {
        par[i] = i+1;
        ret = p1;
    }
    if(ret < p2)
    {
        par[i] = i+2;
        ret = p2;
    }

    return dp[i] = a[i] + ret;
}

void brd(ll i, ll sum)
{
    if(i < 0)
    return;

    if(dp[i] < a[i] + sum)
    {
        dp[i] = a[i] + sum;
        brd(i-1, dp[i]);
        brd(i-2, dp[i]);
    }
}

int main()
{
    ll i, ans;
    cin >> n >> k;
    k--;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i] = INT_MIN;
        par[i] = -1;
    }

    ans = frd(k) - a[k];

    while(par[k] != -1)
        k = par[k];

    for(i = 0; i < n; i++)
        dp[i] = INT_MIN;

    brd(k, 0);

    ans += dp[0] - a[k];

    cout << ans;
}
