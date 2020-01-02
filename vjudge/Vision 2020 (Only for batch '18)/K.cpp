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

ll a[25], n, ans;

void func(ll i, ll s)
{
    if(i == n)
    {
        ans += s;
        return;
    }
    func(i+1, s);
    func(i+1, s|a[i]);
}

int main()
{
    ll i;
    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    func(0, 0);

    cout << ans;
}
