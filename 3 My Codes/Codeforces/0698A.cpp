//Thanks shahed_ahmed
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
    int i, n, a[109], dp[109][4] = {0};
    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    if(a[0] == 1 || a[0] == 3)
        dp[0][1] = 1;
    if(a[0] == 2 || a[0] == 3)
        dp[0][2] = 1;

    for(i = 1; i < n; i++)
    {
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});

        if(a[i] == 1 || a[i] == 3)
            dp[i][1] = max({dp[i-1][0], dp[i-1][2]}) + 1;
        if(a[i] == 2 || a[i] == 3)
            dp[i][2] = max({dp[i-1][0], dp[i-1][1]}) + 1;
    }

    cout << n - max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}
