#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, k, p, q, r, t, caseno = 0, lcs[55][55][55];
    string a, b, c;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        p = a.size();
        q = b.size();
        r = c.size();

        memset(lcs, 0, sizeof(lcs));

        for(i = 1; i <= p; i++)
        {
            for(j = 1; j <= q; j++)
            {
                for(k = 1; k <= r; k++)
                {
                    if(a[i-1] == b[j-1] && a[i-1] == c[k-1])
                        lcs[i][j][k] = 1 + lcs[i-1][j-1][k-1];
                    else if(a[i-1] == b[j-1])
                        lcs[i][j][k] = max(lcs[i-1][j-1][k], lcs[i][j][k-1]);
                    else if(a[i-1] == c[k-1])
                        lcs[i][j][k] = max(lcs[i-1][j][k-1], lcs[i][j-1][k]);
                    else if(b[j-1] == c[k-1])
                        lcs[i][j][k] = max(lcs[i][j-1][k-1], lcs[i-1][j][k]);
                    else
                        lcs[i][j][k] = max({lcs[i-1][j][k], lcs[i][j-1][k], lcs[i][j][k-1]});
                }
            }
        }

        cout << "Case " << ++caseno << ": " << lcs[p][q][r] << endl;
    }
}
