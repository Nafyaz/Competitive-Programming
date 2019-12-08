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
    ll i, n, m;
    cin >> n;
    vector <pair <int, pair<int, int> > > v(n);

    for(i = 0; i < n; i++)
        cin >> v[i].ff;
    for(i = 0; i < n; i++)
        cin >> v[i].ss.ff;
    for(i = 0; i < n; i++)
        cin >> v[i].ss.ss;

    sort(v.begin(), v.end());


    ll x, pos;
    ordered_set <ll> c[3];

    for(i = 0; i < n; i++)
    {
        c[v[i].ss.ff - 1].insert(i);
        c[v[i].ss.ss - 1].insert(i);
    }

    cin >> m;
    for(i = 0; i < m; i++)
    {
        cin >> x;
        if(c[x-1].empty())
        {
            cout << -1 << " ";
            continue;
        }

        pos = *(c[x-1].find_by_order(0));
        cout << v[pos].ff << " ";

        c[v[pos].ss.ff - 1].erase(pos);
        c[v[pos].ss.ss - 1].erase(pos);
    }
}
