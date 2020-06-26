#include<bits/stdc++.h>
using namespace std;

int main()
{
    int dp[55][55], c[55];
    int i, j, k, len, n, l;
    while(1)
    {
        cin >> l;
        if(!l)
            break;
        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> c[i];

        memset(dp, 0, sizeof(dp));

        c[0] = 0;
        c[n+1] = l;

        for(len = 3; len <= n+2; len++)
        {
            for(i = 0; i + len - 1<= n+1; i++)
            {
                j = i + len-1;
//                cout << i << " " << j << endl;
                dp[i][j] = INT_MAX;
                for(k = i+1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + c[j] - c[i]);
                }
            }

        }

        cout << "The minimum cutting is " << dp[0][n+1] << "." << endl;

    }
}
