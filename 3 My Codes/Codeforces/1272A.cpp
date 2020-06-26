//My shitty solution
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
    ll t, a, b, c, x, y, z, mn, v, p, q, r;
    cin >> t;
    while(t--)
    {
        mn = LLONG_MAX;
        cin >> a >> b >> c;
        for(x = -1; x <= 1; x++)
        {
            for(y = -1; y <= 1; y++)
            {
                for(z = -1; z <= 1; z++)
                {
                    p = a+x;
                    q = b+y;
                    r = c+z;

                    v = abs(p - q) + abs(p - r) + abs(q - r);
                    mn = min(v, mn);
                }
            }
        }

        cout << mn << endl;
    }
}
