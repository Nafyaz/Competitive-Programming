#include<bits/stdc++.h>
using namespace std;

int lcs[3009][3009];
string a, b, ans;

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
    memset(lcs, -1, sizeof lcs);
    call(0, 0);

    int i = 0, j = 0;
    string ans;
    while(i < a.size() && j < b.size())
    {
        if(a[i] == b[j])
        {
            ans = ans + a[i];
            i++;
            j++;
        }
        else if(lcs[i+1][j] >= lcs[i][j+1])
            i++;
        else
            j++;
    }

    cout << ans;
}
