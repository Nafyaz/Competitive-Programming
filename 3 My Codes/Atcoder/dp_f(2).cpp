#include<bits/stdc++.h>
using namespace std;

int lcs[3009][3009];
string a, b;

string call(int i, int j)
{
    if(i == 0 || j == 0)
        return "";
    if(a[i-1] == b[j-1])
        return call(i-1, j-1) + a[i-1];
    else if(lcs[i-1][j] >= lcs[i][j-1])
        return call(i-1, j);
    else
        return call(i, j-1);
}

int main()
{
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

    cout << call(n, m);
}
