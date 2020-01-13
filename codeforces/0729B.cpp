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
    int n, m, i, j;
    cin >> n >> m;

    int act[n][m], left[n][m] = {0}, right[n][m] = {0}, up[n][m] = {0}, down[n][m] = {0};

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            cin >> act[i][j];
    }

    for(i = 0; i < n; i++)
    {
        left[i][0] = act[i][0];
        for(j = 1; j < m; j++)
            left[i][j] = max(left[i][j-1], act[i][j]);

        right[i][m-1] = act[i][m-1];
        for(j = m-2; j >= 0; j--)
            right[i][j] = max(right[i][j+1], act[i][j]);
    }



    for(j = 0; j < m; j++)
    {
        up[0][j] = act[0][j];
        for(i = 1; i < n; i++)
            up[i][j] = max(up[i-1][j], act[i][j]);

        down[n-1][j] = act[n-1][j];
        for(i = n-2; i >= 0; i--)
            down[i][j] = max(down[i+1][j], act[i][j]);
    }

//    cout << endl;
//    for(i = 0; i < n; i++)
//    {
//        for(j = 0; j < m; j++)
//            cout << down[i][j] << " ";
//        cout << endl;
//    }

    int ans = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(!act[i][j])
                ans += left[i][j] + right[i][j] + up[i][j] + down[i][j];
//            cout << ans << " ";
        }
//        cout << endl;
    }

    cout << ans;
}
