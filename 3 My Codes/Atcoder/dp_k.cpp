#include<bits/stdc++.h>
using namespace std;

int n, a[102];
int dp[100005][2];

int call(int k, int p)
{
    if(dp[k][p] != -1)
        return dp[k][p];

    int i;
    for(i = 0; i < n && k >= a[i]; i++)
    {
        if(call(k-a[i], p^1) == p)
            return dp[k][p] = p;
    }

    return dp[k][p] = p^1;
}

int main()
{
    int k, i;

    cin >> n >> k;

    for(i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    memset(dp, -1, sizeof dp);
    cout << (call(k, 0)? "Second" : "First");

//    for(i = 0; i <= k; i++)
//        cout << dp[i][0] << " " << dp[i][1] << "\n";
}
