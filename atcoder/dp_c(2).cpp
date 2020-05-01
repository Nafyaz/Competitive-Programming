#include<bits/stdc++.h>
using namespace std;

int n, a[100009][3], dp[100009][3];

int call(int i, int prev)
{
    if(i > n)
        return 0;

    if(prev != -1 && dp[i][prev] != 0)
        return dp[i][prev];

    int ret = -1;
    for(int j = 0; j < 3; j++)
    {
        if(j != prev)
            ret = max(ret, call(i+1, j) + a[i][j]);
    }

    if(prev != -1)
        dp[i][prev] = ret;

    return ret;
}

int main()
{
    int i, j;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j < 3; j++)
            cin >> a[i][j];
    }

    cout << call(1, -1);
}
