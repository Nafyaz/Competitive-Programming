#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

pair<ll, ll> p[300005];

int main()
{
    ll n, w, i, ans = 0, x;

    cin >> n >> w;

    for(i = 0; i < n; i++)
        cin >> p[i].ff >> p[i].ss;

    sort(p, p+n);

    for(i = n-1; i >= 0; i--)
    {
        x = min(w, p[i].ss);
        ans += x*p[i].ff;
        w -= x;
    }

    cout << ans;
}
