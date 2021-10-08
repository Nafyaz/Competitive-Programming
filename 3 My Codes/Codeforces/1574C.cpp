#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll n, m, sum = 0, i, x, y, p, q, ans;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a+n);

    cin >> m;
    for(i = 0; i < m; i++)
    {
        cin >> x >> y;

        p = lower_bound(a, a+n, x) - a;

        ans = LLONG_MAX;
        if(p > 0)
            ans = min(ans, x-a[p-1] + max(0LL, y-sum+a[p-1]));
        if(p < n)
            ans = min(ans, max(0LL, y-sum+a[p]));

        cout << ans << "\n";
    }
}
