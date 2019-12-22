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

int n, a[20][20], dp[20][262144];

int bitmask(int x, int y)
{
    if(x == n)
        return 0;

    if(dp[x][y])
        return dp[x][y];

    for(int i = 0; i < n; i++)
    {
        if(y&(1 << i))
            continue;
        dp[x][y] = max(dp[x][y], a[x][i] + bitmask(x+1, y|(1<<i)));
    }

    return dp[x][y];
}

int main()
{
    int i, j, t, caseno = 0;
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(dp, 0, sizeof(dp));
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                cin >> a[i][j];
        }
        cout << "Case " << ++caseno << ": " << bitmask(0, 0) << endl;
    }
}
