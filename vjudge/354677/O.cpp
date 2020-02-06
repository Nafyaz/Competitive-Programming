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
    ll t, m, a, d, d2, an;
    set<ll> s;
    cin >> t;
    while(t--)
    {
        s.clear();
        cin >> a >> m;
        for(d = 1; d <= sqrt(m); d++)
        {
            if(m%d == 0 && (m/d-1)%a == 0)
            {
                an = m/d-1;
//                cout << "1: " << d*an/a << " ";
                s.insert(d*an/a);
            }

            if(d == 1)
                continue;
            d2 = m/d;
            if(m%d2 == 0 && (m/d2-1)%a == 0)
            {
                an = m/d2-1;
//                cout << "2: " << d2*an/a << " ";
                s.insert(d2*an/a);
            }
        }

        cout << s.size() << endl;
        for(auto u : s)
            cout << u << " ";
        cout << endl;
    }
}
