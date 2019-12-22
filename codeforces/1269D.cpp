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
    ll i, n, ans = 0, a, color[2] = {0};
    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        color[i%2] += a/2;
        color[(i+1)%2] += a - a/2;
    }

    cout << min(color[0], color[1]);
}
