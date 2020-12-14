#include<bits/stdc++.h>
using namespace std;

string a, b;

int dp[65][65][65][65];

int call(int l1, int r1, int l2, int r2)
{
    if(l1 > r1 || l2 > r2)
        return 0;

    if(dp[l1][r1][l2][r2] != -1)
        return dp[l1][r1][l2][r2];

    int ret = 0;
    if(a[l1] == a[r1] && b[l2] == b[r2] && a[l1] == b[l2])
    {
        if(l1 == r1 || l2 == r2)
            ret = 1;
        else
            ret = 2 + call(l1+1, r1-1, l2+1, r2-1);
    }

    ret = max(ret, call(l1+1, r1, l2, r2));
    ret = max(ret, call(l1, r1-1, l2, r2));
    ret = max(ret, call(l1, r1, l2+1, r2));
    ret = max(ret, call(l1, r1, l2, r2-1));

    return dp[l1][r1][l2][r2] = ret;
}

int main()
{
    int t, caseno = 0;

    cin >> t;
    while(t--)
    {
        cin >> a >> b;

        memset(dp, -1, sizeof dp);

        cout << "Case " << ++caseno << ": " << call(0, a.size()-1, 0, b.size()-1) << "\n";
    }
}
