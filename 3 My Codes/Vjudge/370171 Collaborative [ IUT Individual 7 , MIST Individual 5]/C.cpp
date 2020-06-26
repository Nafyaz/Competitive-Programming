#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, k, a[25][25], dp[20][20][40000];
map<ll, ll> mp;
ll x, y;

ll func(ll i, ll j, ll val)
{
//    cout << i << " " << j << " " << val << endl;
    if(i == n || j == m)
        return 0;
    if(i == n-1 && j == m-1 && (val^a[i][j]) == k)
    {
        cout << "gotcha: " << i << " " << j << " " << (val^a[i][j]) << endl;
        return 1;
    }
    else if(i == n-1 && j == m-1)
        return 0;

    if(mp.find(val) != mp.end())
    {
        mp[val] = ++x;
        y = x;
    }
    else
        y = mp[val];

    if(dp[i][j][y] != -1)
    {
        cout << "found: " << i << " " << j << " " << val << endl;
        return dp[i][j][y];
    }

    return dp[i][j][y] = func(i+1, j, val^a[i][j]) + func(i, j+1, val^a[i][j]);
}

int main()
{
    ll i, j;
    cin >> n >> m >> k;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            cin >> a[i][j];
    }

    memset(dp, -1, sizeof dp);
    cout << func(0, 0, 0);
}
