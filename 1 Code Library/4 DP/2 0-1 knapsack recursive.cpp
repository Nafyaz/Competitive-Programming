#include<bits/stdc++.h>
using namespace std;

int n, m, w[1009], p[1009], dp[1009][1009];

int call(int i, int j)
{
    if(i == n)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(j + w[i] > m)
        dp[i][j] = call(i+1, j);
    else
        dp[i][j] = max(call(i+1, j), p[i] + call(i+1, j+w[i]));
    return dp[i][j];
}

int main()
{
    int i, j;

    memset(dp, -1, sizeof dp);

    cin >> n >> m;
    for(i = 0; i < n; i++)
        cin >> w[i] >> p[i];
    cout << call(0, 0);
}