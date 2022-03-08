#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353

ll x[200005], y[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, m, k, q, i, ans;

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> k >> q;

        for(i = 0; i < q; i++)
            cin >> x[i] >> y[i];

        set<ll> rows, cols;
        ans = 1;
        for(i = q-1; i >= 0; i--)
        {
            if(rows.size() == n || cols.size() == m)
                break;

            if(rows.find(x[i]) == rows.end() || cols.find(y[i]) == cols.end())
            {
                ans = (ans * k) % mod;
                rows.insert(x[i]);
                cols.insert(y[i]);
            }
        }

        cout << ans << "\n";
    }
}
