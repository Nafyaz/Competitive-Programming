#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, i, j, k, n, dp[109][109], sum, caseno = 0;
    while(1)
    {
        for(i = 0; i < 109; i++)
        {
            for(j = 0; j < 109; j++)
            {
                if(i == j)
                    dp[i][j] = 0;
                else
                    dp[i][j] = -1;
            }
        }

        cin >> a >> b;
        if(!a && !b)
            break;

        map<int, int> mp;
        i = 1;

        while(1)
        {
            if(mp.find(a) == mp.end())
                mp[a] = i++;
            if(mp.find(b) == mp.end())
                mp[b] = i++;

            n = i;

            a = mp[a];
            b = mp[b];

            dp[a][b] = 1;
            cin >> a >> b;
            if(!a && !b)
                break;
        }


        for(k = 1; k < n; k++)
        {
            for(i = 1; i < n; i++)
            {
                for(j = 1; j < n; j++)
                {
                    if(dp[i][k] != -1 && dp[k][j] != -1)
                    {
                        if(dp[i][j] != -1)
                            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                        else
                            dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }

        sum = 0;
        for(i = 1; i < n; i++)
        {
            for(j = 1; j < n; j++)
            {
                if(i != j)
                    sum += dp[i][j];
            }
        }

        n--;
        cout << fixed;
        cout << "Case " << ++caseno << ": average length between pages = " << setprecision(3) << (double)sum/(n*n - n) << " clicks\n";
    }
}
