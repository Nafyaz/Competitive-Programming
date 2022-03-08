#include<bits/stdc++.h>
using namespace std;

double dp[302][302][302];

int main()
{
    int n, a, i, j, k, cnt[4] = {0}, zeros;
    double e1, e2, e3, e;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        cnt[a]++;
    }

    for(k = 0; k <= n; k++)
    {
        for(j = 0; j <= n; j++)
        {
            for(i = 0; i <= n; i++)
            {
                if(!i && !j && !k)
                    continue;

                zeros = n - i - j - k;

                if(i)
                    e1 = (1 + dp[i-1][j][k]) *i/n;
                else
                    e1 = 0;

                if(j)
                    e2 = (1 + dp[i+1][j-1][k]) *j/n;
                else
                    e2 = 0;

                if(k)
                    e3 = (1 + dp[i][j+1][k-1]) *k/n;
                else
                    e3 = 0;

                e = ((double)zeros/n + e1 + e2 + e3) * n/(n-zeros);

                dp[i][j][k] = e;
            }
        }
    }

    cout << fixed << setprecision(10) << dp[cnt[1]][cnt[2]][cnt[3]];
}
