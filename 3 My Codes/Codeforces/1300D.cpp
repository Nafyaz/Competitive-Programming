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
    ll n, i, j, x, y, side;
    cin >> n;
    vector<pair<ll, ll> > v;
    if(n&1)
        cout << "NO";
    for(i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back({x, y});
    }

//    side = (v[1].ff - v[0].ff)*(v[1].ff - v[0].ff) + (v[1].ss - v[0].ss)*(v[1].ss - v[0].ss);

    pair<ll, ll> p, q;
    for(i = 0; i < n/2; i++)
    {
        j = n/2+i;
        p = {v[(j+1)%n].ff - v[i].ff, v[(j+1)%n].ss - v[i].ss};
        q = {v[j%n].ff - v[i+1].ff, v[j%n].ss - v[i+1].ss};
        if(p != q)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
