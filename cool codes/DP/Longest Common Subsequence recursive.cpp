#include<bits/stdc++.h>
using namespace std;

int lcs[100][100];
string a, b;

int call(int i, int j)
{
    if(i == a.size() || j == b.size())
        return 0;
    if(lcs[i][j] != -1)
        return lcs[i][j];

    if(a[i] == b[j])
        return lcs[i][j] = 1 + call(i+1, j+1);
    else
        return lcs[i][j] = max(call(i+1, j), call(i, j+1));
}

int main()
{
    cin >> a >> b;

    memset(lcs, -1, sizeof(lcs));
    cout << call(0, 0);
}
