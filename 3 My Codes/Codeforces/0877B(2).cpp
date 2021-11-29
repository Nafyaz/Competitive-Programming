#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, dp[3] = {0}, prev[3] = {0};
    string s;

    cin >> s;
    s = s;

    for(i = 0; i < s.size(); i++)
    {
        dp[0] = prev[0] + (s[i] == 'a');
        dp[1] = max(prev[1], prev[0]) + (s[i] == 'b');
        dp[2] = max({prev[2], prev[1], prev[0]}) + (s[i] == 'a');

        prev[0] = dp[0];
        prev[1] = dp[1];
        prev[2] = dp[2];
    }

    cout << max({dp[0], dp[1], dp[2]});
}
