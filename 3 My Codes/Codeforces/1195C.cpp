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

ll i, n, dp[100009][3], h[100009][2];

int main()
{
    cin >> n;

    for(i = 0; i < n; i++)
        cin >> h[i][0];
    for(i = 0; i < n; i++)
        cin >> h[i][1];

    dp[0][0] = h[0][0];
    dp[0][1] = h[0][1];
    dp[0][2] = 0;

    for(i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + h[i][0];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + h[i][1];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]);
    }

    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}
