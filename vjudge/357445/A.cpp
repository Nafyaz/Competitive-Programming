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
//    freopen("out2.txt", "w", stdout);
//    for(ll number = 1; number <= 10000; number++){
    ll i, j, k, l;
    string n;
//    n = to_string(number);
    cin >> n;
    reverse(n.begin(), n.end());

    map<ll, ll> mp;

    for(i = 1; i <= 9; i++)
    {
        mp[i] = mp[i] + (i <= n[0] - '0');
    }


    k = 10, l = n[0] - '0';

    for(i = 1; i < n.size(); i++)
    {
        for(j = 1; j < n[i] - '0'; j++)
        {
            mp[j] = mp[j] + k;
        }
        if(n[i] - '0' != 0)
            mp[n[i] - '0'] = mp[n[i] - '0'] + l+ 1;
        l += k*(n[i] - '0');
        k *= 10;
    }

    ll mxcnt = -1, mx = -1;

    for(auto u : mp)
    {
        if(mxcnt <= u.ss)
        {
            mxcnt = u.ss;
            mx = u.ff;
        }
    }

//    reverse(n.begin(), n.end());
    cout << mx << endl;
//}
}
