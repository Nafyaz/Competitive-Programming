#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("out.txt", "w", stdout);
    int n, i, j, t, w[21];

    while(cin >> n)
    {
        cin >> t;
        for(i = 1; i <= t; i++)
            cin >> w[i];
        int dp[t+1][n+1];
        queue<int> q[t+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(i = 0; i <= n; i++)
        {
            for(j = 1; j <= t; j++)
            {
                if(w[j] > i || dp[j-1][i] > dp[j-1][i-w[j]] + w[j])
                {
                    dp[j][i] = dp[j-1][i];
                    q[j][i] = q[j-1][i];
                }
                else if(dp[j-1][i] < dp[j-1][i-w[j]] + w[j])
                {
                    dp[j][i] = dp[j-1][i-w[j]] + w[j];
                    q[j][i] = q[j-1][i-w[j]];
                    q[j][i].push(w[j]);
                }
                else
                {
                    dp[j][i] = dp[j-1][i];
                    if(q[j-1][i].size() >= q[j-1][i-w[j]].size() + 1)
                        q[j][i] = q[j-1][i];
                    else
                    {
                        q[j][i] = q[j-1][i-w[j]];
                        q[j][i].push(w[j]);
                    }
                }
            }
        }

        while(!q[t][n].empty())
        {
            cout << q[t][n].front() << " ";
            q[t][n].pop();
        }

        cout << "sum:" << dp[t][n] << endl;
    }
}
