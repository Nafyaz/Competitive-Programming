#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, caseno = 0, w, i, j;
    ll dp[70][70] = {0};

    for(i = 0; i < 70; i++)
        dp[i][i] = 1;

    string s;

    cin >> t;

    while(t--)
    {
        cin >> s;

        w = s.size();

        for(i = 1; i <= w; i++)
        {
            for(j = 0; j+i < w; j++)
            {
                dp[j][j+i] = dp[j][j+i-1] + dp[j+1][j+i] - dp[j+1][j+i-1];
                if(s[j] == s[j+i])
                    dp[j][j+i] += dp[j+1][j+i-1] + 1;
            }
        }

        cout << "Case " << ++caseno << ": " << dp[0][w-1] << "\n";
    }
}
