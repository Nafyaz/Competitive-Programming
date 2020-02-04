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

int dp[5000009];

int func(int n)
{
    if(dp[n] != 0)
        return dp[n];
    if(n == 1)
        return 0;
    if(n&(n-1) == 0)
    {
        dp[n] = log2(n);
        return dp[n];
    }
    if(n%2 == 0)
    {
        dp[n] = func(n/2) + 1;
        return dp[n];
    }
    int p1 = func(n-1) + 1;
    int p2 = func(n+1) + 1;

    dp[n] = min(p1, p2);
    return dp[n];
}

int main()
{
    ll i, t, n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        cout << func(n) << endl;
    }
}
