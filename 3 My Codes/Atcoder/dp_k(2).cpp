#include<bits/stdc++.h>
using namespace std;

int a[102];
int dp[100005][2];

int main()
{
    int n, k, i, j;

    cin >> n >> k;

    for(i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    dp[0][0] = 1;
    dp[0][1] = 0;

    for(i = 1; i <= k; i++)
    {
        dp[i][0] = 1;
        dp[i][1] = 0;
        for(j = 0; j < n && a[j] <= i; j++)
        {
            if(dp[i-a[j]][1] == 0)
                dp[i][0] = 0;
            if(dp[i-a[j]][0] == 1)
                dp[i][1] = 1;
        }
    }

    cout << (dp[k][0] == 0? "First" : "Second");
}

