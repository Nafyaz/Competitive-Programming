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

ll a[1000000], mod[1000000];

int main()
{
    ll i, q, x, y, k, ans = 0;

    cin >> q >> x;
    while(q--)
    {
        cin >> y;
        k = y%x;
        if(k + x*mod[k] < 1000000)
            a[k + x*mod[k]] = 1;
        mod[k]++;

        while(a[ans])
            ans++;

        cout << ans << endl;
    }
}
