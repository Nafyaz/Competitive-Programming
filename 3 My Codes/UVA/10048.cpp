#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c, s, q, i, j, k, a, b, w, caseno = 0;
    int dp[109][109];

    while(1)
    {
        cin >> c >> s >> q;

        if(!c && !s && !q)
            break;

        for(i = 1; i <= c; i++)
        {
            for(j = 1; j <= c; j++)
            {
                if(i == j)
                    dp[i][j] = 0;
                else
                    dp[i][j] = -1;
            }
        }

        for(i = 0; i < s; i++)
        {
            cin >> a >> b >> w;
            dp[a][b] = w;
            dp[b][a] = w;
        }

        for(k = 1; k <= c; k++)
        {
            for(i = 1; i <= c; i++)
            {
                for(j = 1; j <= c; j++)
                {
                    if(dp[i][k] != -1 && dp[k][j] != -1)
                    {
                        if(dp[i][j] == -1)
                            dp[i][j] = max(dp[i][k], dp[k][j]);
                        else
                            dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
                    }
                }
            }
        }

        if(caseno != 0)
            cout << "\n";

        cout << "Case #" << ++caseno << "\n";
        for(i = 0; i < q; i++)
        {
            cin >> a >> b;
            if(dp[a][b] == -1)
                cout << "no path\n";
            else
                cout << dp[a][b] << "\n";
        }
    }
}
