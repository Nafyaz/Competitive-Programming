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
    ll t, n, i, flag, x, y;
    map<pair<ll, ll>, ll> mp;
    pair<ll, ll> ans;
    string s;
    cin >> t;
    while(t--)
    {
        mp.clear();
        ans.ss = INT_MAX;
        ans.ff = INT_MIN;
        flag = x = y = 0;
        mp[{x, y}] = 1;
        cin >> n >> s;
        for(i = 0; i < n; i++)
        {
//            cout << x << " " << y << endl;
            if(s[i] == 'L')
                x--;
            if(s[i] == 'R')
                x++;
            if(s[i] == 'U')
                y++;
            if(s[i] == 'D')
                y--;

            if(mp[{x, y}])
            {
                flag = 1;
                if(ans.ss - ans.ff > i+2 - mp[{x, y}])
                {
                    ans.ff = mp[{x, y}] - 1;
                    ans.ss = i;
                }
            }
            mp[{x, y}] = i+2;
        }

        if(flag)
            cout << ans.ff + 1 << " " << ans.ss + 1 << endl;
        else
            cout << -1 << endl;

    }
}
