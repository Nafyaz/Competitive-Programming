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

ll i, n, a[100009], l[100009], r[100009];

int main()
{
//    cout << "lol";
    cin >> n;
    l[0] = -1;
    r[n+1] = -1;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        l[i] = l[i-1] & (~a[i]);
    }

    for(i = n; i >= 1; i--)
    {
        r[i] = r[i+1] & (~a[i]);
    }

    ll mxans = INT_MIN, idx = -1;
    for(i = 1; i <= n; i++)
    {
        if(mxans < (l[i-1] & a[i] & r[i+1]))
        {
            mxans = l[i-1] & a[i] & r[i+1];
            idx = i;
        }
    }

    cout << a[idx] << " ";
    for(i = 1; i <= n; i++)
    {
        if(i != idx)
            cout << a[i] << " ";
    }
}
