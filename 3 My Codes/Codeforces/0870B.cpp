//thanks to editorial
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
    int n, k, i;
    cin >> n >> k;

    int a[n], mx = INT_MIN, mn = INT_MAX;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    if(k >= 3)
        cout << mx;
    else if(k == 2)
        cout << max(a[0], a[n-1]);
    else
        cout << mn;
}
