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
    ll t, a, b, x, y, z, t1, t2;
    cin >> t;
    while(t--)
    {
        cin >> x >> y >> a >> b;
        if((a*y + b*x)%(a+b) != 0)
        {
            cout << -1 << endl;
            continue;
        }
        z = (a*y + b*x)/(a+b);
        if(z < x || z > y)
        {
            cout << -1 << endl;
            continue;
        }
        if((z-x)%a != 0 || (y-z)%b != 0)
        {
            cout << -1 << endl;
            continue;
        }
        t1 = (z-x)/a;
        t2 = (y - z)/b;

        if(t1 != t2 || t1 < 0)
        {
            cout << -1 << endl;
            continue;
        }

        cout << t1 << endl;
    }
}
