#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll lcs[31][31], dp[31][31], n, m;
string a, b;

ll call(ll i, ll j)
{
    if(i == n || j == m)
        return 0;
    if(lcs[i][j] != -1)
        return lcs[i][j];

    if(a[i] == b[j])
    {
        lcs[i][j] = 1 + call(i+1, j+1);
        dp[i][j] = dp[i+1][j+1];
    }
    else
    {
        lcs[i][j] = max(call(i+1, j), call(i, j+1));
        if(lcs[i][j] > lcs[i+1][j] && lcs[i+1][j] != -1)
            dp[i][j] = dp[i+1][j];
        else if(lcs[i][j] < lcs[i][j+1] && lcs[i][j+1] != -1)
            dp[i][j] = dp[i][j+1];
        else
            dp[i][j] = dp[i+1][j] + dp[i][j+1];
    }

    return lcs[i][j];
}

int main()
{
    ll t, caseno = 0, i, j, ans;
    cin >> t;

    while(t--)
    {
        memset(lcs, -1, sizeof(lcs));
        memset(dp, 0, sizeof(dp));

        cin >> a >> b;
        n = a.size();
        m = b.size();

        for(i = 0; i <= n; i++)
            dp[i][m] = 1;
        for(i = 0; i <= m; i++)
            dp[n][i] = 1;

        ans = call(0, 0);
//        for(i = 0; i <= m; i++)
//        {
//            for(j = 0; j <= n; j++)
//                cout << setw(3) << dp[j][i] << setw(3) << lcs[j][i];
//            cout << endl;
//        }

        cout << "Case " << ++caseno << ": " << n+m - ans << " " << dp[0][0] << endl;
    }
}
