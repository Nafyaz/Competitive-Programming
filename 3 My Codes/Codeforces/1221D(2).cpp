#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll vis[300009][3], dp[300009][3];
ll a[300009], b[300009], cs, n;

ll func(ll i, ll j)
{
    if(i == n+1)
        return 0;
    if(vis[i][j] == cs)
        return dp[i][j];
    vis[i][j] = cs;

    ll ret = 1e18+7;
    for(int k = 0; k < 3; k++)
    {
        if(a[i-1] + j != a[i] + k)
            ret = min(ret, b[i]*k + func(i+1, k));
    }

    return dp[i][j] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll t, i;
    cin >> t;
    while(cs < t)
    {
        cs++;
        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> a[i] >> b[i];
        cout << func(1, 0) << endl;
    }
}
