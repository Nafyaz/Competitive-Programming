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

ll n, k, d, dp[101], MOD = 1000000007;

ll call(ll sum, bool taken)
{

    if(sum <= 0 || sum < d && !taken)
    {
//        cout << sum << " " << taken << " " << "0" << endl;;
        return 0;
    }

    int i, x = sum;

    if(dp[x] != 0)
        return dp[x];

    if(!taken)
    {
        for(i = 1; i <= k; i++)
        {
            if(i >= d && i <= sum)
            {
                dp[x]++;
                dp[x] = (dp[x] + call(sum - i, 1))%MOD;
            }
            else
                dp[x] = (dp[x] + call(sum - i, 0))%MOD;
        }
    }

    else
    {
        for(i = 1; i <= k; i++)
            dp[x] = (dp[x] + call(sum - i, 1))%MOD;
    }

//    cout << sum << " " << taken << " " << dp[x] << endl;
    return dp[x];
}

int main()
{
    cin >> n >> k >> d;
    cout << call(n, 0);
}
