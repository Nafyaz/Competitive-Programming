#include<bits/stdc++.h>
using namespace std;

int a[200005];
int dp[200005][2];

int n;
int call(int i, int j)
{
    if(i > n)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ret = INT_MAX;

    if(j == 0)
        ret = min(call(i+1, 1), call(i+2, 1));
    else
        ret = min(a[i] + call(i+1, 0), a[i]+a[i+1] + call(i+2, 0));

    return dp[i][j] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, i;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
        {
            cin >> a[i];
            dp[i][0] = dp[i][1] = -1;
        }

        cout << call(1, 1) << "\n";
    }
}
