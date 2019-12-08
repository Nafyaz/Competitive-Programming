#include<bits/stdc++.h>
using namespace std;
int dia[210][210], dp[210][210], n;

int func(int i, int j)
{
    if(i >= 2*n - 1)
        return 0;
    if(j < 0)
        return 0;
    if(i < n && j > i)
        return 0;
    if(i >= n && j >= 2*n - 1 - i)
        return 0;
    if(dp[i][j] != 0)
        return dp[i][j];
    if(i == 2*n - 2 && j == 0)
    {
        dp[i][j] = dia[i][j];
        return dp[i][j];
    }

//    total += dia[i][j];

    int p1, p2;

    if(i < n - 1)
    {
        p1 = func(i+1, j);
        p2 = func(i+1, j+1);
    }

    else
    {
        p1 = func(i+1, j-1);
        p2 = func(i+1, j);
    }

    dp[i][j] = dia[i][j] + max(p1, p2);
    return dp[i][j];
}

int main()
{
    int T, caseno = 0, i, j, high;

    cin >> T;

    while(T--)
    {
        memset(dia, 0, sizeof(dia));
        memset(dp, 0, sizeof(dp));

        cin >> n;
        for(i = 0; i < 2*n - 1; i++)
        {
            if(i < n)
            {
                for(j = 0; j <= i; j++)
                    cin >> dia[i][j];
            }
            else
            {
                for(j = 0; j < 2*n - 1 - i; j++)
                    cin >> dia[i][j];
            }
        }

        cout << "Case " << ++caseno << ": " << func(0, 0) << endl;

//        for(i = 0; i < 2*n - 1; i++)
//        {
//            for(j = 0; j < n; j++)
//                cout << dia[i][j] << " ";
//            cout << endl;
//        }
    }
}
/*
2
4
7
6 4
2 5 10
9 8 12 2
2 12 7
8 2
10
2
1
2 3
1
*/
