#include<bits/stdc++.h>
using namespace std;

int dp[1000009];

int main()
{
    int t, p, x, ans;

    cin >> t;
    dp[1] = 1;

    while(t--)
    {
        cin >> p;
        ans = 0;
        for(x = 1; x < p; x++)
        {
            dp[x] = 1 + dp[p%x];
            ans += dp[x];
        }

        cout << fixed;
        cout << setprecision(6) << (double)ans/(p-1) << "\n";
    }

}
