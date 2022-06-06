#include<bits/stdc++.h>
using namespace std;

bool dp[109][100009], vis[109][100009];
int n, s, a[109];

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
    int i, j;
    cin >> n >> s;
    for(i = 0; i < n; i++)
        cin >> a[i];

    cout << call(n-1, s) << endl;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= s; j++)
            cout << vis[i][j] << "," << dp[i][j] << "  ";
        cout << endl;
    }
}