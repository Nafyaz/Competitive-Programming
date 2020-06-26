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
    ll n, m, i, j;
    cin >> n >> m;
    ll a[n+1] = {0}, b[m+1] = {0}, cpre[n+1][m+1] = {0};

    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i-1];
    }
    for(i = 1; i <= m; i++)
    {
        cin >> b[i];
        b[i] += b[i-1];
    }
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0)
            {
                cpre[i][j] = 0;
                continue;
            }
            cpre[i][j] = a[i]*b[j] + cpre[i-1][j] + cpre[i][j-1] - cpre[i-1][j-1];
        }
    }

//    for(i = 0; i <= n; i++)
//    {
//        for(j = 0; j <= m; j++)
//            cout << cpre[i][j] << " ";
//        cout << endl;
//    }

    ll x, x1, x2, y1, y2, s, ans = 0, flag;
    cin >> x;

    x1 = x2 = 0;
    while(x1 <= n && x2 <= n)
    {
        flag = y1 = y2 = 0;

        while(y1 <= m && y2 <= m)
        {
            s = cpre[x2][y2] - cpre[x2][y1] - cpre[x1][y2] + cpre[x1][y1];

            if(s <= x)
            {
                if(y1 < y2)
                    flag = 1;
                ans = max(ans, (x2 - x1)*(y2 - y1));
                y2++;
            }
            else
            {
                y1++;
            }
        }

        if(flag)
            x2++;
        else
            x1++;
    }

    cout << ans;
}
