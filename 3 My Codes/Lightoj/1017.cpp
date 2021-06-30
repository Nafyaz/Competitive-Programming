#include<bits/stdc++.h>
using namespace std;

int n, w, y[109];
int dp[109][109];

int func(int i, int k)
{
    if(!k || i >= n)
        return 0;

    if(dp[i][k] != -1)
        return dp[i][k];

    int ret = func(i+1, k);

    int j = lower_bound(y, y+n, y[i] + w+1) - y;

    ret = max(ret, j-i + func(j, k-1));

    return dp[i][k] = ret;
}

int main()
{
    int t, k, i, x, caseno = 0;
    cin >> t;
    while(t--)
    {
        cin >> n >> w >> k;
        for(i = 0; i < n; i++)
            cin >> x >> y[i];
        sort(y, y+n);

        memset(dp, -1, sizeof dp);
        cout << "Case " << ++caseno << ": " << func(0, k) << "\n";
    }
}
