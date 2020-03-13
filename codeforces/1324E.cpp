#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int n, h, l, r, a[2009], dp[2009][2009];

int func(int i, int c)
{
    if(dp[i][c] != -1)
        return dp[i][c];
    if(i == n)
        return 0;

    int x, y, h1 = (c+a[i])%h, h2 = (h1-1+h)%h;

    if(h1 >= l && h1 <= r)
        x = 1 + func(i+1, h1);
    else
        x = func(i+1, h1);

    if(h2 >= l && h2 <= r)
        y = 1 + func(i+1, h2);
    else
        y = func(i+1, h2);

    return dp[i][c] = max(x, y);
}

int main()
{
    int i, j;
    vector<int> pos;
    memset(dp, -1, sizeof(dp));
    cin >> n >> h >> l >> r;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << func(0, 0);
}
