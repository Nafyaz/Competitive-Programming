#include<bits/stdc++.h>
using namespace std;

int dp[25][3], color[25][3], n;

int call(int i, int j)
{
    if(i == n)
        return 0;

    if(j != -1 && dp[i][j])
        return dp[i][j];

    int ret = INT_MAX;
    for(int k = 0; k < 3; k++)
    {
        if(k != j)
            ret = min(ret, call(i+1, k) + color[i][k]);
    }

    return dp[i][j] = ret;
}

int main()
{
    int t, caseno = 0, i, j;
    cin >> t;
    while(t--)
    {
        memset(dp, 0, sizeof(dp));
        cin >> n;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < 3; j++)
                cin >> color[i][j];
        }

        cout << "Case " << ++caseno << ": " << call(0, -1) << endl;
    }
}
