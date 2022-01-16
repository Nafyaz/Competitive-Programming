#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
ll dp[3003][3003];
ll a[3003], pre[3003];

ll call(ll st, ll ed)
{
    if(st == ed)
        return dp[st][ed] = a[st];

    if(dp[st][ed] != -1)
        return dp[st][ed];

    ll left = call(st, ed-1);
    ll right = call(st+1, ed);

//    if((ed-st+1)%2 == n%2)
    return dp[st][ed] = max(pre[ed]-pre[st-1] - left, pre[ed]-pre[st-1] - right);
}

int main()
{
    ll i;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }

//    for(i = 1; i <= n; i++)
//        cout << pre[i] << " ";

    memset(dp, -1, sizeof dp);
    cout << 2*call(1, n) - pre[n];
}
