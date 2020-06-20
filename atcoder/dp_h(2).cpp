#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

string grid[1009];
ll dp[1009][1009];
ll h, w;

ll call(ll i, ll j)
{
    if(i >= h || j >= w || grid[i][j] == '#')
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == h-1 && j == w-1)
        return 1;

    dp[i][j] = (call(i+1, j) + call(i, j+1)) % mod;

    return dp[i][j];
}

int main()
{
    ll i, j;
    cin >> h >> w;
    for(i = 0; i < h; i++)
        cin >> grid[i];

    memset(dp, -1, sizeof dp);
    cout << call(0, 0);
}
