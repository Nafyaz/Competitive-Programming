#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j;
    cin >> n;

    int x, good[n][n];

    memset(good, 0, sizeof(good));

    for(i = 0; i < n; i++)
    {
        good[i][i] = 1;
        good[i][n-i-1] = 1;
        good[n/2][i] = 1;
        good[i][n/2] = 1;
    }

    int ans = 0;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> x;
            if(good[i][j])
                ans += x;
        }
    }

    cout << ans;
}
