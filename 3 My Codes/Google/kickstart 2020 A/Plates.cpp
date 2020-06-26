#include<bits/stdc++.h>
using namespace std;
int n, k, p, beauty[55][35], pre[55][35], dp[55][1509];

int call(int i, int w)
{
    if(i == n)
        return 0;
    if(dp[i][w] != -1)
        return dp[i][w];
    for(int j = 0; j <= k; j++)
    {
        if(w+j <= p)
            dp[i][w] = max(dp[i][w], pre[i][j]+call(i+1, w+j));
    }

    return dp[i][w];
}

int main()
{
    int t, i, j, caseno = 0;
    cin >> t;

    while(t--)
    {
        cin >> n >> k >> p;
        for(i = 0; i < n; i++)
        {
            pre[i][0] = 0;
            for(j = 1; j <= k; j++)
            {
                cin >> beauty[i][j];
                pre[i][j] = pre[i][j-1] + beauty[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << "Case #" << ++caseno << ": " << call(0, 0) << endl;
    }
}
