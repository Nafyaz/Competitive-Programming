#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll perm[11][100005];
ll remap[100005];
ll inSequence[11][100005];
ll maxLenIfStartAt[11][100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, i, j;

    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            cin >> perm[i][j];
    }

    for(i = 0; i < n; i++)
        remap[perm[0][i]] = i+1;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            perm[i][j] = remap[perm[i][j]];
    }

    ll l, r;
    for(i = 0; i < m; i++)
    {
        l = r = 0;
        while(l < n)
        {
            while(r+1 < n && perm[i][r] + 1 == perm[i][r+1])
                r++;
            while(l <= r)
            {
                inSequence[i][l] = r-l+1;
                l++;
            }

            r++;
        }

        for(j = 0; j < n; j++)
            maxLenIfStartAt[i][perm[i][j]] = inSequence[i][j];
    }

    ll mn, ans = 0;

    for(j = 1; j <= n; j++)
    {
        mn = n;
        for(i = 0; i < m; i++)
            mn = min(mn, maxLenIfStartAt[i][j]);

        ans += mn;
    }

    cout << ans;
}
