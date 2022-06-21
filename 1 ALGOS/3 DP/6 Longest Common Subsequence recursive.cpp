#include<bits/stdc++.h>
using namespace std;

int lcs[3009][3009];
string a, b, ans;

int call(int i, int j)
{
    if(i == (int)a.size() || j == (int)b.size())
        return 0;
    if(lcs[i][j] != -1)
        return lcs[i][j];

    if(a[i] == b[j])
        return lcs[i][j] = 1 + call(i+1, j+1);
    else
        return lcs[i][j] = max(call(i+1, j), call(i, j+1));
}

string call2(int i, int j)
{
    if(i == (int)a.size() || j == (int)b.size())
        return "";
    if(a[i] == b[j])
        return a[i] + call2(i+1, j+1);
    else if(lcs[i+1][j] >= lcs[i][j+1])
        return call2(i+1, j);
    else
        return call2(i, j+1);
}

int main()
{
    cin >> a >> b;
    memset(lcs, -1, sizeof lcs);

    cout << call(0, 0) << endl << call2(0, 0);
}
