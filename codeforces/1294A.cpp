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
    ll t, a, b, c, n, mx, mn;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c >> n;
        mx = max({a, b, c});
        mn = min({a, b, c});

        n = n - (mx - a);
        n = n - (mx - b);
        n = n - (mx - c);

        if(n >= 0 && n%3 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
