#include<bits/stdc++.h>
using namespace std;

int n, m, dp[51][8];
string s[51];

int call(int idx, int mask)
{
    if(idx == n && mask != 7)
        return INT_MAX;
    else if(idx == n)
        return 0;

    if(dp[idx][mask] != -1)
        return dp[idx][mask];

    int ret = INT_MAX, temp, new_mask;
    for(int i = 0; i < m; i++)
    {
        new_mask = mask;
        if(s[idx][i] >= '0' && s[idx][i] <= '9')
            new_mask |= 1;
        if(s[idx][i] >= 'a' && s[idx][i] <= 'z')
            new_mask |= 2;
        if(s[idx][i] == '#' || s[idx][i] == '*' || s[idx][i] == '&')
            new_mask |= 4;

        temp = call(idx+1, new_mask);
        if(temp != INT_MAX)
            ret = min(ret, min(i, m-i) + temp);
    }

    return dp[idx][mask] = ret;
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> s[i];

    memset(dp, -1, sizeof dp);

    cout << call(0, 0);
}
