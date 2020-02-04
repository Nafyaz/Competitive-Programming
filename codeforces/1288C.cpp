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

#define MOD 1000000007
ll i, j, n, m, arr[15][1010];

int main()
{
    cin >> n >> m;

    for(j = 1; j <= n; j++)
        arr[0][j] = 1;

    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
            arr[i][j] = (arr[i][j-1] + arr[i-1][j])%MOD;
    }

//    for(i = 1; i <= m; i++)
//    {
//        for(j = 1; j <= n; j++)
//            cout << arr[i][j] << " ";
//        cout << endl;
//    }

//    cout << arr[3][2] << endl;

    ll ans = 0;

    for(i = 1; i <= n; i++)
        ans = (ans + arr[m-1][n-i+1]*arr[m][i])%MOD;

    cout << ans;
}
