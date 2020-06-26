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
    ll i, n, x;
    cin >> n;
    x = n*(n+1)/2;
    if(x&1)
    {
        cout << -1;
        return 0;
    }

    x /= 2;
    string ans(n, '+');
    for(i = n; i > 0 && x; i--)
    {
        if(x <= i)
        {
            ans[x-1] = '-';
            x = 0;
        }
        else
        {
            x -= i;
            ans[i-1] = '-';
        }
    }

    cout << ans;
}
