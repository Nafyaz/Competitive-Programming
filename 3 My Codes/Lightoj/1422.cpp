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
    int t, i, j, n, caseno = 0, c[110], dp[110];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> c[i];
        for(i = 0; i < n; i++)
            dp[i] = 1;

        for(i = 1; i < n; i++)
        {
            for(j = 0; j < i; j++)
            {
                if(c[j] <= c[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        int mx = -1;
        for(i = 0; i < n; i++)
            mx = max(mx, dp[i]);
        cout << "Case " << ++caseno << ": " << mx << endl;
    }
}
