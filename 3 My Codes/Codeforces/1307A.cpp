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
    int t, n, d, a[109], i, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> d;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            if(i > 0)
            {
                k = min(d/i, a[i]);
                a[0] += k;
                d -= k*i;
            }
        }

        cout << a[0] << endl;
    }
}

