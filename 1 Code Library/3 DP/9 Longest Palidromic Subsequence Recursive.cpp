#include<bits/stdc++.h>
using namespace std;

string s;
int dp[1009][1009];

int lps(int i, int j)
{
    if(i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    int ret = 0;
    if(s[i] == s[j])
    {
        if(i == j)
            ret = 1;
        else
            ret = 2 + lps(i+1, j-1);
    }

    ret = max(ret, lps(i+1, j));
    ret = max(ret, lps(i, j-1));

    return dp[i][j] = ret;
}

int main()
{
    cin >> s;

    memset(dp, -1, sizeof dp);

    cout << lps(0, (s.size() - 1)) << "\n";
}


