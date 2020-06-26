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
    int t, n, sum, ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans = 0;

        while(n > 9)
        {
            ans += n/10*10;
            n = n%10 + n/10;
        }

        ans += n;
        cout << ans << endl;
    }
}
