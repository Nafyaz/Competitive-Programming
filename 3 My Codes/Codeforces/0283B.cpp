#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
ll a[200005];
ll dp[200005][2];
bool vis[200005][2];

ll call(ll i, ll j)
{
    if(i > n || i <= 0)
        return 0;

    if(dp[i][j] != 0)
        return dp[i][j];

    if(vis[i][j])
        return dp[i][j] = -1;
    vis[i][j] = 1;

    if(j == 0)
    {
        if(call(i-a[i], 1) != -1)
            return dp[i][j] = a[i] + call(i-a[i], 1);
        else
            return dp[i][j] = -1;
    }
    else
    {
        if(call(i+a[i], 0) != -1)
            return dp[i][j] = a[i] + call(i+a[i], 0);
        else
            return dp[i][j] = -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i;

    cin >> n;

    for(i = 2; i <= n; i++)
        cin >> a[i];

    vis[1][1] = 1;
    for(i = 2; i <= n; i++)
    {
        if(call(i, 0) == -1)
            cout << "-1\n";
        else
            cout << i-1 + call(i, 0) << "\n";
    }
}
