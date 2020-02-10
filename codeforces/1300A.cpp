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
    int t, i, n, a[109], sum, ans;
    cin >> t;
    while(t--)
    {
        sum = ans = 0;
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            if(a[i] == 0)
            {
                sum ++;
                a[i]++;
                ans++;
            }
        }
        if(sum == 0)
            ans++;
        cout << ans << endl;
    }
}
