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
    ll n, i, f, mxf = 0;
    cin >> n;
    ll a[n], diff1[n], diff2[n];

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i > 0)
        {
            diff1[i-1] = (i&1? abs(a[i] - a[i-1]) : -abs(a[i] - a[i-1]));
            diff2[i-1] = (i&1? -abs(a[i] - a[i-1]) : abs(a[i] - a[i-1]));
        }
    }

    f = 0;
    for(i = 0; i < n-1; i++)
    {
        f += diff1[i];
        if(f < 0)
            f = 0;
        mxf = max(mxf, f);
    }

    f = 0;
    for(i = 0; i < n-1; i++)
    {
        f += diff2[i];
        if(f < 0)
            f = 0;
        mxf = max(mxf, f);
    }

    cout << mxf;
}
