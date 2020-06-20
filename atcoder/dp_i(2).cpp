#include<bits/stdc++.h>
using namespace std;

double p[3009], dp[3009][3009], ans;
int n, vis[3009][3009];

double call(int i, int j)
{
    if(vis[i][j])
        return dp[i][j];
    vis[i][j] = 1;

    if(!i && !j)
        return dp[i][j] = 1;

    if(!j)
        dp[i][j] = call(i-1, j) * (1 - p[i]);
    else if (i < j)
        return 0;
    else
        dp[i][j] = call(i-1, j) * (1 - p[i]) + call(i-1, j-1) * p[i];

    return dp[i][j];
}

int main()
{
    int i;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> p[i];

    for(i = n/2 + 1; i <= n; i++)
        ans += call(n, i);

    cout << fixed << setprecision(9) << ans;
}
