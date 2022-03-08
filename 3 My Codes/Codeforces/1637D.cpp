#include<bits/stdc++.h>
using namespace std;

int n, a[102], b[102];
int Total;
int dp[102][10004];

int call(int i, int aSum)
{
    if(i > n)
        return aSum;

    if(dp[i][aSum] != -1)
        return dp[i][aSum];

    int ret1 = call(i+1, aSum);
    int ret2 = call(i+1, aSum - a[i] + b[i]);

    if(abs(2*ret1 - Total) < abs(2*ret2 - Total))
        return dp[i][aSum] = ret1;
    else
        return dp[i][aSum] = ret2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, i, aSum, bSum, squaredSum;

    cin >> T;

    while(T--)
    {
        cin >> n;

        squaredSum = 0;

        aSum = 0;
        for(i = 1; i <= n; i++)
        {
            cin >> a[i];
            aSum += a[i];
            squaredSum += a[i]*a[i];
        }

        bSum = 0;
        for(i = 1; i <= n; i++)
        {
            cin >> b[i];
            bSum += b[i];
            squaredSum += b[i]*b[i];
        }

        Total = aSum + bSum;
        memset(dp, -1, sizeof dp);

        aSum = call(1, aSum);
        bSum = Total - aSum;

//        cout << aSum << " " << bSum << " " << Total << " " << squaredSum << "\n";

        cout << aSum*aSum + bSum*bSum + squaredSum*(n-2) << "\n";
    }
}
