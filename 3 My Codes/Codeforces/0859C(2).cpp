#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, a[51], k;
    int dp[2] = {0};

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    k = 0;
    for(i = n-1; i >= 0; i--)
    {
        dp[!k] += a[i];

        if(dp[!k] > dp[k])
            k = !k;
    }

    cout << dp[!k] << " " << dp[k];
}
