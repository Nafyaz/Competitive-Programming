#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, n, m;
    string x, y;

    cin >> x >> y;

    n = x.size(), m = y.size();
    int d[n+1][m+1] = {0};

    for(i = 1; i <= n; i++)
        d[i][0] = i;
    for(i = 1; i <= m; i++)
        d[0][i] = i;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            d[i][j] = min(d[i-1][j] + 1, d[i][j-1] + 1);
            if(x[i] == y[j])
                d[i][j] = min(d[i][j], d[i-1][j-1]);
            else
                d[i][j] = min(d[i][j], d[i-1][j-1] + 2);
        }
    }

    cout << d[n][m];
}
