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

ll x, y, p, k;
string sheet[15];

ll price()
{
    ll i, j, ans = p;
    for(i = 0; i < x; i++)
    {
        for(j = 0; j < y; j++)
        {
            if(sheet[i][j] != '.')
                ans += k;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n, i, j, q, b;
    ll cost[100009], pre[100009];
    cin >> t;
    while(t--)
    {
        cin >> n >> x >> y;
        cin >> p >> k;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < x; j++)
                cin >> sheet[j];
            cost[i] = price();
        }

        sort(cost, cost + n);

        pre[0] = cost[0];
        for(i = 1; i < n; i++)
            pre[i] = pre[i-1] + cost[i];

        cin >> q;
        while(q--)
        {
            cin >> b;
            cout << upper_bound(pre, pre + n, b) - pre << endl;
        }
    }
}
