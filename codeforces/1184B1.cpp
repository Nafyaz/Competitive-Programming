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
    ll i, s, b;
    cin >> s >> b;
    ll a[s];
    vector <pair<ll, ll> > v(b+1);

    for(i = 0; i < s; i++)
        cin >> a[i];
    for(i = 1; i <= b; i++)
        cin >> v[i].ff >> v[i].ss;

    sort(v.begin(), v.end());

    for(i = 1; i <= b; i++)
        v[i].ss += v[i-1].ss;

    ll pos;
    for(i = 0; i < s; i++)
    {
        pos = upper_bound(v.begin(), v.end(), make_pair(a[i], LLONG_MAX)) - v.begin();
        cout << v[pos-1].ss << " ";
    }
}
