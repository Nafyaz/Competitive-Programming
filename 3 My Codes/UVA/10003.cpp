#include<bits/stdc++.h>
using namespace std;

int dp[55][55], c[55];

int call(int i, int j)
{
    if(i+1 >= j)
        return 0;
    if(dp[i][j])
        return dp[i][j];

    int ret = INT_MAX;
    for(int k = i+1; k < j; k++)
    {
        ret = min(ret, call(i, k) + call(k, j) + c[j] - c[i]);
    }

    return dp[i][j] = ret;
}

int main()
{
    int l, n, i;

    while(1)
    {
        cin >> l;
        if(!l)
            break;
        cin >> n;
        c[0] = 0;
        c[n+1] = l;
        for(i = 1; i <= n; i++)
            cin >> c[i];

        memset(dp, 0, sizeof(dp));
        cout << "The minimum cutting is " << call(0, n+1) << "." << endl;
    }

}
