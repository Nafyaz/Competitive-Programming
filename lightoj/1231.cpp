#include<bits/stdc++.h>
using namespace std;

int main()
{
    int dp[55][1009], t, i, j, l, n, k, caseno = 0, x, y;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        memset(dp, 0, sizeof dp);

        vector<int> a, c;
        for(i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }
        for(i = 0; i < n; i++)
        {
            cin >> y;
            c.push_back(y);
        }

        for(i = 0; i <= k; i++)
            dp[0][i] = 0;
        for(i = 0; i < n; i++)
            dp[i][0] = 1;

        for(i = 1; i <= k; i++)
        {
            for(j = 0; j < n; j++)
            {
                for(l = 0; l <= c[j] && i >= l*a[j]; l++)
                    dp[j+1][i] = (dp[j+1][i] + dp[j][i - l*a[j]])%100000007;
            }
        }

//        for(i = 0; i <= n; i++)
//        {
//            for(j = 0; j <= k; j++)
//                cout << dp[i][j] << " ";
//            cout << endl;
//        }

        cout << "Case " << ++caseno << ": " << dp[n][k] << endl;
    }
}
