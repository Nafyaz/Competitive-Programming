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
    ll t, i, n, s, ans, mn;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans = 0;
        mn = INT_MAX;
        for(i = 1; i <= n; i++)
        {
            cin >> s;
            mn = min(mn, s);
            ans += mn;
        }

        cout << ans << endl;
    }
}
