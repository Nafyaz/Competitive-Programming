#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

string grid[1009];
ll dp[1009][1009];
ll h, w;

int main()
{
    ll i, j;
    cin >> h >> w;
    for(i = 0; i < h; i++)
        cin >> grid[i];

    for(i = 1; i <= h; i++)
    {
        for(j = 1; j <= w; j++)
        {
            if(i == 1 && j == 1)
            {
                dp[i][j] = 1;
                continue;
            }

            if(grid[i-1][j-1] == '.')
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }

    cout << dp[h][w];
}
