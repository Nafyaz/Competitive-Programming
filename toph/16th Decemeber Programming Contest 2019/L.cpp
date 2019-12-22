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
    ll t, caseno = 0, n, i, j, a[65];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];

        cout << "Case " << ++caseno << ": ";

        ll mx = INT_MIN, multi;
        for(i = 0; i < n; i++)
        {
            multi = 1;
            for(j = i; j < n; j++)
            {
                multi *= a[j];
                mx = max(mx, multi);
            }
        }

        cout << mx << endl;
    }
}
