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
    ll t, i, n, k, a[100009], need[100009], sum, mn;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i = 0; i < n; i++)
            cin >> a[i];

        need[n] = 0;
        for(i = n-1; i >= 0; i--)
            need[i] = need[i+1] + (k - a[i]%k)%k;

//        for(i = 0; i <= n; i++)
//            cout << need[i] << " ";

        sum = 0;
        mn = INT_MAX;
        for(i = 0; i <= n; i++)
        {
//            cout << sum << " " << mn << endl;
            if(sum < need[i])
            {
                sum += a[i];
                continue;
            }
            mn = min(mn, (sum - need[i])%k);
            sum += a[i];
        }

        cout << mn << endl;
    }
}
