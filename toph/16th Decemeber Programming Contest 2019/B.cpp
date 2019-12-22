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

ll mulmod(ll a, ll b, ll m)
{
    if(b == 0)
        return 0;

    ll x = 0, y;
    if(b%2 == 1)
        x = a%m;

    y = mulmod(a, b/2, m);
    return (2*y + x)%m;
}

int main()
{
    ll t, n, k, l, mod = 1000000000000000000;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> l;
        cout << mulmod(n+2*l-1, k, mod) << endl;
    }
}
