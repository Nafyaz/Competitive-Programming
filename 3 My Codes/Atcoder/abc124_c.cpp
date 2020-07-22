#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, dp[100009][2];
    string s;
    cin >> s;

    dp[0][0] = dp[0][1] = 0;

    for(i = 0; i < s.size(); i++)
    {
        dp[i+1][0] = dp[i][1] + (s[i] == '0');
        dp[i+1][1] = dp[i][0] + (s[i] == '1');
    }

    cout << min(dp[s.size()][0], dp[s.size()][1]);
}
