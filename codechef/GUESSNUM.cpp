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
    ll t, m, a, d, i, n, sq;
    set<ll> nset;
    cin >> t;

    while(t--)
    {
//        cout << "lol" << endl;
        nset.clear();
        cin >> a >> m;
        sq = sqrt(m) + 1;
        for(i = 1; i < sq; i++)
        {
            if(m%i == 0)
            {
                d = m/i;
                if((m/d - 1)%a == 0 && (m/d-1)/a*d > 0)
                    nset.insert((m/d-1)/a*d);
                d = i;
                if((m/d - 1)%a == 0 && (m/d-1)/a*d > 0)
                    nset.insert((m/d-1)/a*d);
            }
        }

        cout << nset.size() << endl;
        for(auto u : nset)
            cout << u << " ";
        cout << endl;
    }
}
