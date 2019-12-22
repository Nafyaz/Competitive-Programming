#include<bits/stdc++.h>
using namespace std;

#define num 30009

int main()
{
    long long i, j, dp[6][num], n;
    long long c[5] = {1, 5, 10, 25, 50};
    long long ans;

    memset(dp, 0, sizeof(dp));
    for(i = 1; i <= 5; i++)
        dp[i][0] = 1;

    for(i = 1; i <= 5; i++)
    {
        for(j = 1; j < num; j++)
        {
//            cout << i << " " << j << " " << c[i-1] << endl;

            if(j >= c[i-1])
            {
                dp[i][j] = dp[i-1][j] + dp[i][j - c[i-1]];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

//    for(i = 0; i <= 5; i++)
//    {
//        for(j = 0; j <= 5; j++)
//            cout << dp[i][j] << " ";
//        cout << endl;
//    }


    while(scanf("%d", &n) == 1)
    {
        ans = dp[5][n];

        if(ans > 1)
            printf("There are %lld ways to produce %d cents change.\n", ans, n);
        else
            printf("There is only 1 way to produce %d cents change.\n", n);
    }
}

