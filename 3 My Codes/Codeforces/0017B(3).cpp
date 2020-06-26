#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, m, q, i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> q;

    vector<ll> v(n+1, INT_MAX);
    ll ans = 0;
    cin >> m;
    for(i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v[b] = min(v[b], c);
    }

    bool ok = 1;
    for(i = 1; i <= n; i++)
    {
        if(v[i] == INT_MAX && ok)
            ok = 0;
        else if(v[i] == INT_MAX)
        {
            cout << -1;
            return 0;
        }
        else
            ans += v[i];
    }

    cout << ans;
}
