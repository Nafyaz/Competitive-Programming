#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

bool rain[2003];
int umb[2003];
int dp[2003][2003];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, n, m, i, j, l, r, x, p;

    cin >> a >> n >> m;

    for(i = 0; i < n; i++)
    {
        cin >> l >> r;

        for(j = l; j < r; j++)
            rain[j] = 1;
    }

    memset(umb, -1, sizeof umb);
    for(i = 0; i < m; i++)
    {
        cin >> x >> p;

        if(umb[x] == -1)
            umb[x] = p;
        else
            umb[x] = min(umb[x], p);
    }

    for(i =  0; i < a; i++)
    {
        for(j = 0; j < a; j++)
            dp[i][j] = INT_MAX;
    }

    dp[0][0] = 0;

    for(i = 0; i < a; i++)
    {

    }
}
