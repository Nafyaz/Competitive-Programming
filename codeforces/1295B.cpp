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
    ll t, n, x, i, diff[100009], maxdiff, mindiff, ans, k;
    map<int, int> mp;
    string s;
    cin >> t;
    while(t--)
    {
        maxdiff = INT_MIN;
        mindiff = INT_MAX;
        cin >> n >> x >> s;

        mp.clear();

        for(i = 0; i < n; i++)
        {
            if(i > 0)
            {
                if(s[i] == '0')
                    diff[i] = diff[i-1] + 1;
                else
                    diff[i] = diff[i-1] - 1;
            }
            else
            {
                if(s[i] == '0')
                    diff[i] = 1;
                else
                    diff[i] = -1;
            }

            maxdiff = max(maxdiff, diff[i]);
            mindiff = min(mindiff, diff[i]);

            mp[diff[i]]++;
        }

//        for(auto u : mp)
//            cout << u.ff << " " << u.ss << endl;

        if(x == 0 && diff[n-1] != 0)
        {
            cout << 1 + mp[0] << endl;
            continue;
        }
        if(diff[n-1] == 0 && x >= mindiff && x <= maxdiff)
        {
            cout << -1 << endl;
            continue;
        }
        if(x > maxdiff && diff[n-1] <= 0)
        {
            cout << 0 << endl;
            continue;
        }
        if(x < mindiff && diff[n-1] >= 0)
        {
            cout << 0 << endl;
            continue;
        }


        ans = 0;
        if(diff[n-1] > 0 && x > 0)
        {
            k = x%diff[n-1];
            x = diff[n-1] * min(x/diff[n-1], maxdiff/diff[n-1]) + k;
            while(x >= mindiff)
            {
//                cout << x << " " << ans << endl;
                ans += mp[x];
                x -= diff[n-1];
            }
            cout << ans << endl;
            continue;
        }

        if(diff[n-1] < 0 && x < 0)
        {
            k = x%diff[n-1];
            x = diff[n-1] * min(x/diff[n-1], mindiff/diff[n-1]) + k;
            while(x <= maxdiff)
            {
                ans += mp[x];
                x -= diff[n-1];
            }
            cout << ans << endl;
            continue;
        }
        if(diff[n-1] > 0 && x < 0)
        {
            while(x <= maxdiff)
            {
                ans += mp[x];
                x += diff[n-1];
            }
            cout << ans << endl;
            continue;
        }
        if(diff[n-1] < 0 && x > 0)
        {
            while(x >= mindiff)
            {
                ans += mp[x];
                x += diff[n-1];
            }
            cout << ans << endl;
            continue;
        }
    }
}
