#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll dp[102][100005];
ll a[102];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, i, j;

    cin >> n >> k;

    for(i = 1; i <= n; i++)
        cin >> a[i];

    for(i = 0; i <= n; i++)
        dp[i][0] = 1;

    for(j = 1; j <= k; j++)
    {
        for(i = 1; i <= n; i++)
        {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1];
        }
    }

//    cout << dp[n][k];

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= k; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
}
