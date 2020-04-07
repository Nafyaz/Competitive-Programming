#include<bits/stdc++.h>
using namespace std;

bool dp[109][100009], vis[109][100009];
int n, total, a[109], ans;

bool call(int i, int j)
{
    if(vis[i][j])
        return dp[i][j];

    vis[i][j] = 1;

    if(i == 0 && a[i] == j || j == 0)
        return dp[i][j] = 1;
    else if(i == 0)
        return dp[i][j] = 0;

    if(j >= a[i])
        return dp[i][j] = call(i-1, j) | call(i-1, j-a[i]);
    else
        return dp[i][j] = call(i-1, j);
}

int main()
{
    int t, i, j;
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(vis, 0, sizeof vis);
        total = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            total += a[i];
        }

        ans = 0;
        for(i = 0; i <= total; i++)
            ans += (call(n-1, i)? i : 0);
        cout << ans << endl;
    }
}
