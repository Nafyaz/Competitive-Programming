#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

int main()
{
    ll n, m, k, x, s;
    cin >> n >> m >> k >> x >> s;
    ll a[m+1], b[m+1], c[k], d[k];

    ll i, j;
    for(i = 1; i <= m; i++)
        cin >> a[i];
    for(i = 1; i <= m; i++)
        cin >> b[i];
    for(i = 0; i < k; i++)
        cin >> c[i];
    for(i = 0; i < k; i++)
        cin >> d[i];

    a[0] = x, b[0] = 0;
    ll p, pos, mn = x*n;

    for(i = 0; i <= m; i++)
    {
        if(b[i] > s)
            continue;
        p = s - b[i];
        mn = min(mn, a[i]*n);

        pos = lower_bound(d, d+k, p+1) - d - 1;

        if(pos >= 0)
            mn = min(mn, a[i]*max(0LL, n - c[pos]));
    }

    cout << mn;
}
