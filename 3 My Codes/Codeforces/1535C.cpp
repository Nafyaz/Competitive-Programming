#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll T, i, ans, dp[2], temp[2];
    string s;

    cin >> T;

    while(T--)
    {
        cin >> s;

        dp[0] = dp[1] = 0;
        ans = 0;

        for(i = 0; i < s.size(); i++)
        {
            temp[0] = dp[0];
            temp[1] = dp[1];
            if(s[i] == '0')
            {
                dp[0] = temp[1] + 1;
                dp[1] = 0;
            }
            else if(s[i] == '1')
            {
                dp[0] = 0;
                dp[1] = temp[0] + 1;
            }
            else
            {
                dp[0] = temp[1] + 1;
                dp[1] = temp[0] + 1;
            }
            ans += max(dp[0], dp[1]);
        }

        cout << ans << "\n";
    }
}
