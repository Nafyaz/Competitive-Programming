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
    int t, n, i, ans, x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans = log10(n);
        ans *= 9;
        x = 1;
        while((int)log10(x) < (int)log10(n))
            x = 10*x + 1;

        for(i = 1; i*x <= n; i++)
        {
            ans++;
        }

        cout << ans << endl;
    }
}
