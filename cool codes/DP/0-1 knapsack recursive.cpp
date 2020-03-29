#include<bits/stdc++.h>
using namespace std;

int n, m, w[1009], p[1009], dp[1009][1009];

int call(int i, int j)
{
    if(i == n+1)
        return 0;
    if(dp[i][j])
        return dp[i][j];
    if(j + w[i] > m)
        dp[i][j] = call(i+1, j);
    else
        dp[i][j] = max(call(i+1, j), p[i] + call(i+1, j+w[i]));
    return dp[i][j];
}

int main()
{
    int i, j;
    cin >> n >> m;
    for(i = 0; i < n; i++)
        cin >> w[i] >> p[i];
    cout << call(0, 0);
}
/*
4 8
2 1
3 2
4 4
5 8
*/
