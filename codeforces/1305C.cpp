#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define ff first
#define ss second

int main()
{
    ll n, m, i, j;
    cin >> n >> m;
    ll a[n];
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = a[i];
    }

    if(n > m)
    {
        cout << 0;
        return 0;
    }

    ll ans = 1;

    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            ans = (ans*(abs(a[i] - a[j])))%m;
        }
    }

    cout << ans;
}
