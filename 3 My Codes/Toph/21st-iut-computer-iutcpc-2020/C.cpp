/*
Check and remove this section while coding
1. Get rid of toolbars except compiler and main. Enable only logs and status.
2. Use C++17 in global compiler settings.
3. Turn on Wall, Wextra, Wshadow in warnings.
4. Make tab spout 4 spaces
*/

/*
ID: nafis.f1
TASK:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back

int n, m, h;
int h[20][20];

int main()
{
    int t, i, j;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
                cin >> h[i][j];
        }


    }
}
