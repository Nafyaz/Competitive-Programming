#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200009

ll dp[N][3], a[N];

int main()
{
    ll t, n, i;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];
        for(i = 0; i < n; i++)
        {
            dp[i + 1][0] = dp[i][0] + (i % 2 == 0) * a[i];
            dp[i + 2][1] = max(dp[i][0], dp[i][1]) + (i % 2 == 0 ? a[i + 1] : a[i]);
            dp[i + 1][2] = max({dp[i][0], dp[i][1], dp[i][2]}) + (i % 2 == 0) * a[i];
        }

        cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
    }
}
