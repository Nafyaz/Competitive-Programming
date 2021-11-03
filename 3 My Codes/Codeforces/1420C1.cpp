#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[300005], n;
ll dp[300005][2];

ll func(int i, bool willAdd)
{
    if(i >= n)
        return 0;
    if(dp[i][willAdd] != -1)
        return dp[i][willAdd];

    ll ret = func(i+1, willAdd);

    if(willAdd == 1)
        ret = max(ret, a[i] + func(i+1, 0));
    else
        ret = max(ret, -a[i] + func(i+1, 1));

    return dp[i][willAdd] = ret;
}

int main()
{
    ll T, q, i;

    cin >> T;

    while(T--)
    {
        cin >> n >> q;

        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            dp[i][0] = dp[i][1] = -1;
        }

        cout << func(0, 1) << "\n";
    }
}
