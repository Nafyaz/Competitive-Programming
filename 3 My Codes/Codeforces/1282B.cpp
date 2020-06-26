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

ll n, k, a[200009], dp[200009];

int main()
{
    ll t, p, i, sum;
    cin >> t;
    while(t--)
    {
        cin >> n >> p >> k;
        for(i = 1; i <= n; i++)
        {
            cin >> a[i];
            dp[i] = INT_MAX;
        }
        sort(a+1, a+n+1);

        dp[0] = 0;
        for(i = 1; i <= n; i++)
        {
            if(dp[i-1] + a[i] <= p)
                dp[i] = min(dp[i], dp[i-1] + a[i]);

            if(i >= k && dp[i-k] + a[i] <= p)
                dp[i] = min(dp[i], dp[i-k] + a[i]);
        }

//        for(i = 0; i <= n; i++)
//            cout << dp[i] << " ";
        for(i = n; i >= 0; i--)
        {
            if(dp[i] != INT_MAX)
            {
                cout << i << endl;
                break;
            }
        }
    }
}
