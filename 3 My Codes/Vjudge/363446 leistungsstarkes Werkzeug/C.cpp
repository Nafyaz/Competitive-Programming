#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s[100009][2];
ll n, i, c[100009], dp[100009][2];

int main()
{
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> c[i];
    for(i = 0; i < n; i++)
    {
        cin >> s[i][0];
        s[i][1] = s[i][0];
        reverse(s[i][1].begin(), s[i][1].end());
    }

    for(i = 0; i < n; i++)
        dp[i][0] = dp[i][1] = LLONG_MAX - 2*(ll)INT_MAX;

    dp[0][0] = 0;
    dp[0][1] = c[0];

    for(i = 1; i < n; i++)
    {
        if(s[i][0] >= s[i-1][0])
            dp[i][0] = min(dp[i][0], dp[i-1][0]);
        if(s[i][0] >= s[i-1][1])
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
        if(s[i][1] >= s[i-1][0])
            dp[i][1] = min(dp[i][1], dp[i-1][0] + c[i]);
        if(s[i][1] >= s[i-1][1])
            dp[i][1] = min(dp[i][1], dp[i-1][1] + c[i]);
    }

//    for(i = 0; i < n; i++)
//        cout << dp[i][0] << " ";
//    cout << endl;
//    for(i = 0; i < n; i++)
//        cout << dp[i][1] << " ";
//    cout << endl;
    if(dp[n-1][0] == LLONG_MAX - 2*(ll)INT_MAX && dp[n-1][1] == LLONG_MAX - 2*(ll)INT_MAX)
        cout << -1;
    else
        cout << min(dp[n-1][0], dp[n-1][1]);
}
