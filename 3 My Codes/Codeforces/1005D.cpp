#include<bits/stdc++.h>
using namespace std;

int pre[200005];
int lastSame[200005], x[3];
int dp[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i;
    string s;

    cin >> s;

    x[0] = 0;
    x[1] = x[2] = -1;
    lastSame[0] = -1;
    for(i = 1; i <= s.size(); i++)
    {
        pre[i] = (pre[i-1] + (s[i-1]-'0'))%3;
        lastSame[i] = x[pre[i]];
        x[pre[i]] = i;
    }

    for(i = 1; i <= s.size(); i++)
    {
        if(lastSame[i] == -1)
            dp[i] = dp[i-1];
        else
            dp[i] = max(dp[i-1], dp[lastSame[i]] + 1);
    }

    cout << dp[s.size()];
}
