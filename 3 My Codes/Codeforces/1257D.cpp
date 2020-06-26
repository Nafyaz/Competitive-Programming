#include<bits/stdc++.h>
using namespace std;

int n, m, mp[200009], hp[200009], hs[200009];
int dp[200009];

int func(int d, int h)
{
    if(dp[d] != -1)
        return dp[d];

    if(d >= n)
        return 0;

    if(mp[d] > hp[h])
        return 300000;


    int ret = 300000, s = hs[h];
    while(s--)
    {
        if(mp[d] > hp[h])
            break;
        d++;
        if(d >= n)
            return 1;
    }

    for(int i = 0; i < m; i++)
    {
        ret = min(ret, func(d, i));
    }

    dp[d] = ret;
    return min(300000, dp[d] + 1);
}

int main()
{
    int t, i, j, ans;
    cin >> t;

    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> mp[i];
            dp[i] = -1;
        }

        cin >> m;
        for(i = 0; i < m; i++)
            cin >> hp[i] >> hs[i];

        ans = 300000;
        for(i = 0; i < m; i++)
            ans = min(ans, func(0, i));

        ans >= 200000 + 10? cout << -1 : cout << ans;
        cout << endl;
    }
}
