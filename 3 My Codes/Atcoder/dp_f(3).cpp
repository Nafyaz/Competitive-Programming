#include<bits/stdc++.h>
using namespace std;

int lcs[3009][3009];

int main()
{
    string a, b;
    int i, j, n, m;
    cin >> a >> b;

    n = a.size();
    m = b.size();

    for(i = 0; i <= n; i++)
        lcs[i][0] = 0;
    for(i = 0; i <= m; i++)
        lcs[0][i] = 0;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(a[i-1] == b[j-1])
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }

    i = n, j = m;
    string ans;
    while(i > 0 && j > 0)
    {
        if(a[i-1] == b[j-1])
        {
            ans = a[i-1] + ans;
            i--;
            j--;
        }
        else if(lcs[i-1][j] >= lcs[i][j-1])
            i--;
        else
            j--;
    }

    cout << ans;
}

