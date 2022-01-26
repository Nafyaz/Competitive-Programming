#include<bits/stdc++.h>
using namespace std;

int n, a[51];
int pre[51];
int dp[51][2];

int call(int i, int d)
{
    if(i > n)
        return 0;

    if(dp[i][d] != -1)
        return dp[i][d];

    int ret1 = pre[n] - pre[i-1] - call(i+1, !d);
    int ret2 = call(i+1, d);

    if(ret1 > ret2)
        return dp[i][d] = ret1;
    else
        return dp[i][d] = ret2;
}

int main()
{
    int i, alice, bob, sum = 0;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        pre[i] = pre[i-1] + a[i];
    }

    memset(dp, -1, sizeof dp);

    bob = call(1, 1);
    alice = sum - bob;

    cout << alice << " " << bob;
}
