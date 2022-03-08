#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

bool isInside(ll c, ll r, ll x, ll y)
{
    return (x-c)*(x-c) + y*y - r*r <= 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, x, y, i, pos, ans;
    pair<pair<ll, ll>, ll> c[10004];
    ll hits[10004];

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> c[i].ff.ff >> c[i].ff.ss;
        c[i].ff.ff -= c[i].ff.ss;
        c[i].ss = i;

        hits[i] = -1;
    }

    sort(c, c+n);

    cin >> m;

    ans = 0;
    for(i = 1; i <= m; i++)
    {
        cin >> x >> y;
        pos = lower_bound(c, c+n, make_pair(make_pair(x, LLONG_MAX), LLONG_MAX)) - c;

        if(pos > 0 && hits[c[pos-1].ss] == -1 && isInside(c[pos-1].ff.ff + c[pos-1].ff.ss, c[pos-1].ff.ss, x, y))
        {
            hits[c[pos-1].ss] = i;
            ans++;
        }
        if(pos > 1 && hits[c[pos-2].ss] == -1 && isInside(c[pos-2].ff.ff + c[pos-2].ff.ss, c[pos-2].ff.ss, x, y))
        {
            hits[c[pos-2].ss] = i;
            ans++;
        }
    }

    cout << ans << "\n";
    for(i = 0; i < n; i++)
        cout << hits[i] << " ";
}
