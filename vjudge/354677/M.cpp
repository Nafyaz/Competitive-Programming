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
    ll t, n, k, i, mxi;
    cin >> t;
    while(t--)
    {
        mxi = INT_MIN;
        cin >> n >> k;
        if(n < k*(k+1)/2)
        {
            cout << -1 << endl;
            continue;
        }

        for(i = 1; i <= sqrt(n); i++)
        {
            if(n%i == 0 && n/i >= k*(k+1)/2)
                mxi = max(mxi, i);
            if(n%i == 0 && i >= k*(k+1)/2)
                mxi = max(mxi, n/i);
        }

        cout << mxi << endl;
    }
}
