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

int t[50009][6];

int main()
{
    int m, n, i, j;
    cin >> m >> n;

    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cin >> t[i][j];
            t[i][j] = max(t[i-1][j], t[i][j-1]) + t[i][j];
        }
        cout << t[i][n] << " ";
    }
}
