#include<bits/stdc++.h>
using namespace std;

int p, q, r, lcs[55][55][55];
string a, b, c;

int call(int i, int j, int k)
{
    if(i == p || j == q || k == r)
        return 0;
    if(lcs[i][j][k] != -1)
        return lcs[i][j][k];

    if(a[i] == b[j] && a[i] == c[k])
        lcs[i][j][k] = 1 + call(i+1, j+1, k+1);
    else if(a[i] == b[j])
        lcs[i][j][k] = max(call(i+1, j+1, k), call(i, j, k+1));
    else if(a[i] == c[k])
        lcs[i][j][k] = max(call(i+1, j, k+1), call(i, j+1, k));
    else if(b[j] == c[k])
        lcs[i][j][k] = max(call(i, j+1, k+1), call(i+1, j, k));
    else
        lcs[i][j][k] = max({call(i+1, j, k), call(i, j+1, k), call(i, j, k+1)});

    return lcs[i][j][k];
}

int main()
{
    int t, caseno = 0;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        p = a.size();
        q = b.size();
        r = c.size();
        memset(lcs, -1, sizeof(lcs));
        cout << "Case " << ++caseno << ": " << call(0, 0, 0) << endl;
    }
}
