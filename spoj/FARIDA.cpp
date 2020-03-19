#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, i, n, caseno = 0;
    ll a[10009], dp[10009][2];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            dp[i][0] = dp[i][1] = 0;
        }

        if(n >= 1)
        {
            dp[0][0] = a[0];
            dp[0][1] = 0;
        }
        if(n >= 2)
        {
            dp[1][0] = a[1];
            dp[1][1] = a[0];
        }

        for(i = 2; i < n; i++)
        {
            dp[i][0] = max(dp[i-1][1], dp[i-2][1]) + a[i];
            dp[i][1] = max(dp[i-1][0], dp[i-2][0]);
        }

        cout << "Case " << ++caseno << ": ";
        if(n == 1)
            cout << a[0] << endl;
        else
            cout << max(dp[n-1][0], dp[n-2][0]) << endl;
    }
}

