#include<bits/stdc++.h>
using namespace std;

int w[260], sum[260];
int dp[260][260];

int call(int i, int j)
{
    int k, ret = INT_MAX;

    if(i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    for(k = i; k <= j; k++)
        ret = min(ret, (sum[j] - sum[i-1] - w[k]) + call(i, k-1) + call(k+1, j));

    return dp[i][j] = ret;
}

int main()
{
    int n, i;

    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
        {
            cin >> w[i];
            sum[i] = sum[i-1] + w[i];
        }

        memset(dp, -1, sizeof dp);
        cout << call(1, n) << "\n";
    }
}
