#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll s[100005];
ll Log[100005];
ll minSparse[100005][20];
ll maxSparse[100005][20];

ll getMin(ll l, ll r)
{
    ll k = Log[r-l+1];

    return min(minSparse[l][k], minSparse[r - (1LL << k) + 1][k]);
}

ll getMax(ll l, ll r)
{
    ll k = Log[r-l+1];

    return max(maxSparse[l][k], maxSparse[r - (1LL << k) + 1][k]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll t, caseno = 0, n, a, i, j, l, r, mn, mx, ans;

    Log[1] = 0;
    for(i = 2; i < 100005; i++)
        Log[i] = Log[i>>1] + 1;

    cin >> t;

    while(t--)
    {
        cin >> n >> a;

        for(i = 0; i < n; i++)
        {
            cin >> s[i];

            minSparse[i][0] = s[i];
            maxSparse[i][0] = s[i];
        }

        for(j = 1; (1 << j) <= n; j++)
        {
            for(i = 0; i + (1 << j) <= n; i++)
            {
                minSparse[i][j] = min(minSparse[i][j-1], minSparse[i + (1LL << (j-1))][j-1]);
                maxSparse[i][j] = max(maxSparse[i][j-1], maxSparse[i + (1LL << (j-1))][j-1]);
            }
        }

        ans = l = r = 0;
        while(r < n)
        {
            mn = getMin(l, r);
            mx = getMax(l, r);

            if(mx - mn <= a)
            {
                ans = max(ans, r-l+1);
                r++;
            }
            else
                l++;
        }

        cout << "Case #" << ++caseno << ": " << ans << "\n";
    }
}
