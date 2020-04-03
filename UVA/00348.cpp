#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, k, len, a, b, dp[15][15], s[15][15];
    vector<int> dims;
    while(1)
    {
        cin >> n;
        if(!n)
            break;
        for(i = 0; i < n; i++)
        {
            cin >> a >> b;
            if(!i)
                dims.push_back(a);
            dims.push_back(b);
        }


        vector<int> st, ed;
        for(len = 2; len <= n+1; len++)
        {
            for(i = 1; i + len-1 <= n+1; i++)
            {
                j = i+len-1;
                dp[i][j] = INT_MAX;
                pair<int, int> p, q;
                for(k = i; k < j; k++)
                {
                    if(dp[i][j] > dp[i][k] + dp[k+1][j] + dims[i-1]*dims[k]*dims[j])
                    {
                        dp[i][j] = dp[i][k] + dp[k+1][j] + dims[i-1]*dims[k]*dims[j];
                        s[i][j] = k;
                    }
                }

            }
        }



    }
}
/*
3
1  5
5  20
20  1
*/
