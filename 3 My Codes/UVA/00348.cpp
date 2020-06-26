#include<bits/stdc++.h>
using namespace std;

long long s[15][15], dp[15][15];

void Backtracking(long long l, long long r)
{
    if(l+1 < r)
    {
        long long m = s[l][r];
        cout << '(';
        Backtracking(l, m);
        cout << " x ";
        Backtracking(m+1, r);
        cout << ')';
    }
    if(l == r)
        cout << 'A' << l;
    if(l+1 == r)
        cout << "(A" << l << " x A" << r << ')';
}

int main()
{
//    freopen("out.txt", "w", stdout);
    long long caseno = 0, n, i, j, k, len, a, b;
    while(1)
    {
        cin >> n;
        if(!n)
            break;

        vector<long long> dims;

        for(i = 0; i < n; i++)
        {
            cin >> a >> b;
            if(!i)
                dims.push_back(a);
            dims.push_back(b);
        }

        for(i = 0; i <= n+1; i++)
            dp[i][i] = 0;

        for(len = 2; len <= n+1; len++)
        {
            for(i = 1; i + len - 1 < n+1; i++)
            {
                j = i+len-1;
                dp[i][j] = INT_MAX;
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

//        for(i = 0; i <= n+1; i++)
//        {
//            for(j = 0; j <= n+1; j++)
//                cout << dp[i][j] << " ";
//            cout << endl;
//        }

        cout << "Case " << ++caseno << ": ";
        Backtracking(1, n);
        cout << endl;
    }
}
/*
3
1  5
5  20
20  1
3
5  10
10  20
20  35
6
30  35
35  15
15  5
5  10
10  20
20  25
0
*/
