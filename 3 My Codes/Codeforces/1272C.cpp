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
    ll n, k, i, j;
    ll avail[26] = {0};
    string s, t;

    cin >> n >> k >> s;
    while(k--)
    {
        cin >> t;
        avail[t[0] - 'a'] = 1;
    }

    ll x = 0, ans = 0;
    for(i = 0; i < s.size(); i++)
    {
        if(avail[s[i] - 'a'])
            x++;
        else
            x = 0;
        ans += x;
    }
    cout << ans;
}
