#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll grid[1003][1003];
ll dp1[1003][1003];
ll dp2[1003][1003];
ll dp3[1003][1003];
ll dp4[1003][1003];

int main()
{
    ll n, m, i, j;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
            cin >> grid[i][j];
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
            dp1[i][j] = grid[i][j] + max(dp1[i-1][j], dp1[i][j-1]);
    }

    for(i = n; i >= 1; i--)
    {
        for(j = m; j >= 1; j--)
            dp2[i][j] = grid[i][j] + max(dp2[i+1][j], dp2[i][j+1]);
    }

    for(i = n; i >= 1; i--)
    {
        for(j = 1; j <= m; j++)
            dp3[i][j] = grid[i][j] + max(dp3[i+1][j], dp3[i][j-1]);
    }

    for(i = 1; i <= n; i++)
    {
        for(j = m; j >= 1; j--)
            dp4[i][j] = grid[i][j] + max(dp4[i-1][j], dp4[i][j+1]);
    }

//    for(i = 1; i <= n; i++)
//    {
//        for(j = 1; j <= m; j++)
//            cout << dp4[i][j] << " ";
//        cout << "\n";
//    }

    ll lahub, lahubina, ans = 0;
    for(i = 2; i < n; i++)
    {
        for(j = 2; j < m; j++)
        {
//            cout << i << " " << j << ": ";

            lahub = dp1[i-1][j] + dp2[i+1][j];
            lahubina = dp3[i][j-1] + dp4[i][j+1];
//            cout << lahub << " " << lahubina << "; ";
            ans = max(ans, lahub+lahubina);

            lahub = dp1[i][j-1] + dp2[i][j+1];
            lahubina = dp3[i+1][j] + dp4[i-1][j];
//            cout << lahub << " " << lahubina << "\n";
            ans = max(ans, lahub+lahubina);
        }
    }

    cout << ans;
}
