#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll a[300009], b[300009], dp[300009][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll q, n, i, j;
    cin >> q;
    while(q--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i] >> b[i];
        for(i = 0; i <= n; i++)
        {
            for(j = 0; j < 3; j++)
                dp[i][j] = LLONG_MAX;
        }

        dp[0][0] = 0;
        dp[0][1] = b[0];
        dp[0][2] = 2*b[0];

        for(i = 1; i < n; i++)
        {
            for(j = 0; j < 3; j++)
            {
                if(a[i] + j != a[i-1])
                    dp[i][j] = min(dp[i][j], dp[i-1][0] + j*b[i]);
                if(a[i] + j != a[i-1] + 1)
                    dp[i][j] = min(dp[i][j], dp[i-1][1] + j*b[i]);
                if(a[i] + j != a[i-1] + 2)
                    dp[i][j] = min(dp[i][j], dp[i-1][2] + j*b[i]);
            }
        }

        cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
    }
}
