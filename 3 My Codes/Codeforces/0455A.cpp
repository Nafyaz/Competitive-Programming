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
ll n, dp[100009], freq[100009];
ll func(ll i)
{
    if(i == 0)
        return 0;
    if(i == 1)
        return freq[1];
    if(dp[i] != -1)
        return dp[i];

    dp[i] = max(func(i-1), i*freq[i] + func(i-2));

    return dp[i];
}
int main()
{
    ll i, x, mx = 0;
    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> x;
        freq[x]++;
        mx = max(mx, x);
    }

    memset(dp, -1, sizeof(dp));
    cout << func(mx);
}
