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
    ll t, i, n, p, x, ans;
    cin >> t;
    while(t--)
    {
        ans = 0;
        cin >> n >> p;

        if(n == 0)
        {
            cout << p << endl;
            continue;
        }

        if(p == 1)
        {
            cout << 0 << endl;
            continue;
        }
        x = (p >> (n-1));

        if((x << (n-1))+1 <= p)
            ans += x;
        else
            ans += x-1;

        if((x << (n-1))-1<= p && (x << (n-1))-2 > 0)
            ans += x;
        else
            ans += x-1;


        x = (p >> n);
        if((x << n)+1 <= p)
            ans += x;
        else
            ans += x-1;

        cout << ans << endl;

    }
}
